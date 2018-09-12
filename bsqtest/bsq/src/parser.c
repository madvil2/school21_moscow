#include "../include/headers.h"

char	**read_map(int file)
{
	char	*line;
	char	**str_map = malloc(sizeof(char*) * get_next_line(file, &line));

	line = malloc(1024);
	while (get_next_line(file, &line) > 0)
	{
		*str_map = line;
		str_map++;
	}
	return (str_map);
}

int	main(int ac, char **av)
{
	int file = open(av[1], O_RDONLY);
	char **map = read_map(file);

	int i = 0;
	int j = 0;
	int ymax = 27;
	int xmax = 10;

	while (map[i] != 0)
	{
		while (map[j] != '\0') 
		{
				printf("%c ", map[i][j]);
				j++;
		}
		map++;
		printf("\n");
	}
	printf("\n");
}

/*


char **nmap_create(char *map)
{
	char **nmap;
	int j;
	int k = 0;

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
	map = read_map(file);
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
	printf("\n"); // wtf is this?!?
	nmap = nmap_create(map);
	map_print(nmap, lines, empty, obstacle, full);
	return (0);
}
*/