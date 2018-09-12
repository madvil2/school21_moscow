#ifndef HEADERS_H
# define HEADERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <time.h>

# define BUFF_SIZE 4096

typedef	struct		s_gnl
{
	char			*arr;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

int		str_len(char *str);
int		count_lines(char *str);
int		ft_not_atoi(char *str);
void	map_print(char **map, int lines, char empty, char obstacle, char full);
int		str_len2(char **str);
int		**imap_create(char **map, int lines, char empty, char obstacle);
char	**genmap(int x, int y);
void	ft_putchar(char c);
void	ft_putnbr(int nb);


void	*ft_memalloc(size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strsub(char const *s, size_t start, size_t len);
int		get_next_line(const int fd, char **line);



#endif
