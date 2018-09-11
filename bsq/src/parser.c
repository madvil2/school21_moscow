#include "../include/headers.h"

char	*read_map(int file, char *av)
{
	int		i = 0;
	int		j = 0;
	int		rd = 1;
	char	*str_map;
	char	buffer[BUFF_SIZE + 1];

	while (rd)
	{
		buffer[rd] = '\0';
		str_map = buffer;
		rd = read(file, buffer, BUFF_SIZE);
	}
	return (str_map);
}

char **nmap_create(char *map)
{
	char **nmap;
	int j;
	int k = 0;

	int n = count_lines(map);
	nmap = (char **)malloc(count_lines(map) * sizeof(char *) + 1);
	j = 0;
	while (*map)
	{
		nmap[j] = (char *)malloc(str_len(map) * sizeof(char) + 1);
		k = 0;
		while (*map != '\n')
		{
			nmap[j][k] = *map;
			k++;
			map++;
		}
		nmap[j][k] = '\0';
		map++;
		j++;
	}
	nmap[j] = 0;
	return (nmap);
}

int		main(int ac, char **av)
{
	int file;
	char *map;
	char **nmap;
	int j = 0;
	int k = 0;

	file = open(av[1], O_RDONLY);
	map = read_map(file, av[1]);

	while (*map >= '0' && *map <= '9')
		map++;
	map--;
	int lines = ft_not_atoi(map);
	map++;
	char empty = *map;
	map++;
	char obstacle = *map;
	map++;
	char full = *map;
	map = map + 2;

	printf("%d %c %c %c\n", lines, empty, obstacle, full);

	nmap = nmap_create(map);

	int i = 0;
	j = 0;
	/*
	while (nmap[i] != 0)
	{
		j = 0;			
		while (nmap[i][j] != '\0')
		{
			printf("%c", nmap[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	*/

	map_print(nmap, lines, empty, obstacle, full);

	return (0);
}