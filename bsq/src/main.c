/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 23:28:33 by pcollio-          #+#    #+#             */
/*   Updated: 2018/09/12 23:38:32 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/headers.h"

int		main(int ac, char **av)
{
	char		*line;
	char		**str_map;
	int			i;
	int			file;
	t_bsq		b;

	b.tic = clock();
	if (ac == 1)
		return (-1);
	file = open(av[1], O_RDONLY);
	if (get_next_line(file, &line) < 0)
		return (-1);
	b.lines = ft_atoi(line);
	str_map = malloc(sizeof(*str_map) * (b.lines + 1));
	i = 0;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	b.empty = line[i++];
	b.obstacle = line[i++];
	b.full = line[i];
	free(line);
	i = 0;
	while (get_next_line(file, &line) > 0)
		str_map[i++] = line;
	str_map[i] = NULL;
	map_print(str_map, &b);
	return (0);
}
