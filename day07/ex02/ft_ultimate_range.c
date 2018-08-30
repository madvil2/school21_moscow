/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 01:41:18 by pcollio-          #+#    #+#             */
/*   Updated: 2018/08/30 02:45:41 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int *arr;
	int i;
	int count;

	count = max - min;
	i = 0;
	if(count <= 0)
	{
		range = 0;
		return (0);
	}	
	arr = (int *)malloc((max - min) * sizeof(int *));
	while (i < count)
	{
		arr[i] = min;
		i++;
		min++;
	}
	*range = arr;
	return (sizeof(range));
}
