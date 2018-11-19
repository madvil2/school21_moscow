/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 23:38:44 by pcollio-          #+#    #+#             */
/*   Updated: 2018/09/12 23:38:45 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/headers.h"

int		validate(char **map, t_bsq *b)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
			if (map[i][j] != b->obstacle && map[i][j] != b->empty)
				return (0);
	}
	i = 1;
	while (map[i] != NULL)
	{
		if (str_len(map[i]) != str_len(map[0]))
			return (0);
		i++;
	}
	return (1);
}
