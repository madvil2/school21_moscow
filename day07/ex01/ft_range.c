/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 22:39:54 by pcollio-          #+#    #+#             */
/*   Updated: 2018/08/30 01:54:59 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *arr;
	int i;

	i = 0;
	if(min >= max)
		return (0);
	arr = (int *)malloc((max - min) * sizeof(int));
	while(min < max)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (arr);
}
