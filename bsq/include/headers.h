/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 23:39:46 by pcollio-          #+#    #+#             */
/*   Updated: 2018/09/12 23:39:48 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <time.h>

# include <stdio.h>

# define BUFF_SIZE 4096

typedef	struct		s_gnl
{
	char			*arr;
	int				fd;
	struct s_gnl	*next;

}					t_gnl;

typedef	struct		s_bsq
{
	char		empty;
	char		obstacle;
	char		full;
	int			lines;
	int			cols;
	clock_t		tic;

}					t_bsq;

typedef	struct		s_algo
{
	int		i;
	int		j;
	int		**imap;
	int		n;
	int		flag;
	int		indexi;
	int		indexj;

}					t_algo;

// void	map_print(char **map, int lines, char empty, char obstacle, char full);
char	**genmap(int x, int y);
int		**imap_create(char **map, t_bsq *b, t_algo *a);
void	map_print(char **map, t_bsq *b);

void	ft_bzero(void *s, size_t n);
void	*ft_memalloc(size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strsub(char const *s, size_t start, size_t len);
void	ft_putchar(char c);
void	ft_putstr(const char *str);
void	ft_putnbr(int nb);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
int		get_next_line(const int fd, char **line);

#endif
