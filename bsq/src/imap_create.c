/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imap_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 23:38:17 by pcollio-          #+#    #+#             */
/*   Updated: 2018/09/12 23:38:19 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/headers.h"

void	create1(int **imap, char **map, t_bsq *b, t_algo *a)
{
	int		i;
	int		j;

	i = -1;
	while (++i < b->lines)
	{
		j = -1;
		while (++j < b->cols)
		{
			if (map[i][j] == b->empty)
				imap[i + 1][j + 1] = 0;
			else if (map[i][j] == b->obstacle)
				imap[i + 1][j + 1] = 1;
			imap[i + 1][j + 1] = imap[i + 1][j + 1] +
			imap[i][j + 1] + imap[i + 1][j] - imap[i][j];
		}
	}
}

int		**imap_create(char **map, t_bsq *b, t_algo *a)
{
	int		i;
	int		j;
	int		**imap;

	i = 0;
	imap = malloc((b->lines + 1) * sizeof(int *));
	while (i < (b->lines + 1))
		imap[i++] = malloc((b->cols + 1) * sizeof(int));
	i = 0;
	j = 0;
	while (j < (b->cols + 1))
		imap[0][j++] = 0;
	while (i < (b->lines + 1))
		imap[i++][0] = 0;
	create1(imap, map, b, a);
	return (imap);
}
