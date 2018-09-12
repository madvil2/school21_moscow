#include "../include/headers.h"


size_t		ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}


void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = n % sizeof(size_t);
	while (i)
	{
		--i;
		((unsigned char *)s)[i] = 0;
	}
	n /= sizeof(size_t);
	while (n)
	{
		--n;
		((size_t *)s)[n] = 0;
	}
}

void	*ft_memalloc(size_t size)
{
	void	*buf;

	buf = (void *)malloc(size);
	if (buf != NULL)
		ft_bzero(buf, size);
	return (buf);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	buf = (char *)malloc(sizeof(*buf) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (buf == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		buf[i++] = s1[j++];
	j = 0;
	while (s2[j])
		buf[i++] = s2[j++];
	buf[i] = '\0';
	return (buf);
}

char	*ft_strsub(char const *s, size_t start, size_t len)
{
	char	*buf;
	size_t	i;

	if (s == NULL)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		buf[i++] = s[start++];
	buf[i] = '\0';
	return (buf);
}

static	ssize_t	find_n(const char *mas)
{
	ssize_t		i;

	i = 0;
	while (mas[i] && mas[i] != '\n')
		i++;
	return (i);
}

static	int		write_arr(char **arr, ssize_t *ret, const int fd, char *fr_arr)
{
	char		*buf;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while ((*arr)[find_n(*arr)] != '\n' && (*ret = read(fd, buf, BUFF_SIZE)))
	{
		if (*ret < 0)
			return (-1);
		buf[(*ret)] = '\0';
		fr_arr = *arr;
		if (!((*arr) = ft_strjoin(*arr, buf)))
			return (-1);
		free(fr_arr);
	}
	free(buf);
	return (0);
}

static	int		get_first_line(char **arr, char **line, ssize_t ret)
{
	ssize_t			i;
	char			*free_old_arr;

	free_old_arr = NULL;
	i = find_n(*arr);
	if ((*arr)[i] == '\n' || (i && !ret))
	{
		if (!((*line) = ft_strsub(*arr, 0, i)))
			return (-1);
		free_old_arr = *arr;
		*arr = ft_strsub(*arr, (i + 1), (ft_strlen(*arr) - i));
		free(free_old_arr);
	}
	else
		return (0);
	return (1);
}

static	int		make_new_fd(const int fd, t_gnl **poi, t_gnl *l)
{
	if (!((*poi) = ((t_gnl *)malloc(sizeof(t_gnl)))))
		return (-1);
	if (!((*poi)->arr = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
	{
		free(*poi);
		return (-1);
	}
	(*poi)->fd = fd;
	(*poi)->next = NULL;
	while (l && l->next && fd != l->fd)
		l = l->next;
	if (l && !(l->next))
		l->next = *poi;
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static	t_gnl	*l;
	t_gnl			*poi;
	char			*free_old_arr;
	ssize_t			ret;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	free_old_arr = NULL;
	if (!l && (make_new_fd(fd, &l, NULL) == -1))
		return (-1);
	poi = l;
	while (poi && fd != poi->fd)
		poi = poi->next;
	if (!poi && (make_new_fd(fd, &poi, l) == -1))
		return (-1);
	if (write_arr(&(poi->arr), &ret, fd, free_old_arr) == -1)
		return (-1);
	return (get_first_line(&(poi->arr), line, ret));
}