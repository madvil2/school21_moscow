#include "../include/headers.h"

char	**genmap(int x, int y)
{
	int		i;
	int		j;
	int		dens = 2;
	char	**arr = malloc(x * sizeof(char *));

	for(i = 0; i < x; i++)
		arr[i] = malloc(y * sizeof(char));

	for (i = 0; i < y; i++) 
	{
		for (j = 0; j < x; j++) 
		{
			if (((rand() % y) * 2) < dens)
				arr[i][j] = 'o';
			else
				arr[i][j] = '.';
		}
	}
	return (arr);
}

int		**imap_create(char **map, int lines, char empty, char obstacle)
{
	int i = 0;
	int j = 0;
	int ymax = str_len2(map);
	int xmax = lines;
	int **imap = malloc((xmax + 1) * sizeof(int *));
	
	for(i = 0; i < (xmax + 1); i++)
		imap[i] = malloc((ymax + 1) * sizeof(int));

	i = 0;
	j = 0;
	while (j < (ymax + 1))
		imap[0][j++] = 0;
	while (i < (xmax + 1))
		imap[i++][0] = 0;
	i = 0;
	while (i < xmax)
	{
		j = 0;
		while (j < ymax)
		{
			if(map[i][j] == empty)
				imap[i + 1][j + 1] = 0;
			else if(map[i][j] == obstacle)
				imap[i + 1][j + 1] = 1;
			imap[i + 1][j + 1] = imap[i + 1][j + 1] + imap[i][j + 1] + imap[i + 1][j] - imap[i][j];
			j++;
		}
		i++;
	}
	return (imap);
}

void	map_print(char **map, int lines, char empty, char obstacle, char full)
{
	clock_t tic = clock();

	int ymax = str_len2(map);
	int xmax = lines;
	int i = 0;
	int j = 0;
	int **imap = imap_create(map, lines, empty, obstacle);
	int n;
	int flag;
	int indexi;
	int indexj;

	free(imap);
	indexi = 0;
	indexj = 0;
	n = 0;
	flag = 1;
	while (flag == 1)
	{
		n++;  
		flag = 0;
		i = 1;
		while (i < xmax + 1)
		{
			j = 1;
			while (j < ymax + 1)
			{
				if ((i - n) >= 0 && (j - n) >= 0)
				{
					if ((imap[i][j] - imap[i - n][j] - imap[i][j - n] + imap[i - n][j - n]) == 0)
					{
						flag = 1;
						indexi = i;
						indexj = j;
						break;
					}
					if (flag)
						break;
				}
				j++;
				if (flag)
					break;
			}
			i++;
			if (flag)
				break;
		}
	}
	i = indexi - n + 1;
	j = indexj - n + 1;
	int nj = j;
	while (i < indexi)
	{
		j = nj;
		while (j < indexj)
		{
			map[i][j] = full;
			j++;
		}
		i++;
	}
	printf("\n");
	for (i = 0; i < xmax; i++) 
	{
		for (j = 0; j < ymax; j++) 
				printf("%c ", map[i][j]);
		printf("\n");
	}
	free(map);
	clock_t toc = clock();
	printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
}
