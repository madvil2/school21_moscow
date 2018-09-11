#ifndef HEADERS_H
# define HEADERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <time.h>

# define BUFF_SIZE 4096

int		str_len(char *str);
int		count_lines(char *str);
int		ft_not_atoi(char *str);
void	map_print(char **map, int lines, char empty, char obstacle, char full);
int		str_len2(char **str);
int		**imap_create(char **map, int lines, char empty, char obstacle);
char	**genmap(int x, int y);

#endif
