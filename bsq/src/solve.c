/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 23:38:39 by pcollio-          #+#    #+#             */
/*   Updated: 2018/09/12 23:38:40 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/headers.h"

void	drei(int **imap, char **map, t_bsq *b)
{
	int			i;
	clock_t		ti;

	i = -1;
	while (++i < b->lines)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
	}
	ti = (clock() - b->tic) / CLOCKS_PER_SEC;
	ft_putstr("Elapsed: ");
	if (ti == 0)
		ft_putstr("0.1");
	else
		ft_putnbr(ti);
	ft_putstr(" seconds\n");
	i = -1;
	while (map[++i])
	{
		free(map[i]);
		free(imap[i]);
	}
}

void	zvei(char **map, t_bsq *b, t_algo *a)
{
	int		i;
	int		j;
	int		nj;

	i = a->indexi - a->n + 1;
	nj = a->indexj - a->n + 1;
	while (i < a->indexi)
	{
		j = nj;
		while (j < a->indexj)
		{
			map[i][j] = b->full;
			j++;
		}
		i++;
	}
}

void	ein(char **map, t_bsq *b, t_algo *a)
{
	while (a->flag == 1)
	{
		a->n++;
		a->flag = 0;
		a->i = 0;
		while (++a->i < b->lines + 1)
		{
			a->j = 0;
			while (++a->j < b->cols + 1)
				if ((a->i - a->n) >= 0 && (a->j - a->n) >= 0 &&
				((a->imap[a->i][a->j] - a->imap[a->i - a->n][a->j] -
				a->imap[a->i][a->j - a->n] +
				a->imap[a->i - a->n][a->j - a->n]) == 0))
				{
					a->flag = 1;
					a->indexi = a->i;
					a->indexj = a->j;
					break ;
				}
		}
	}
}

void	map_print(char **map, t_bsq *b)
{
	t_algo		a;

	b->cols = ft_strlen(*map);
	ft_bzero(&a, sizeof(t_algo));
	a.imap = imap_create(map, b, &a);
	a.flag = 1;
	ein(map, b, &a);
	zvei(map, b, &a);
	drei(a.imap, map, b);
}
