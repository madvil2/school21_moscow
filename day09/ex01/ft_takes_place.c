/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 09:42:40 by pcollio-          #+#    #+#             */
/*   Updated: 2018/08/30 21:46:07 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_xm(int hour)
{
	return ((hour >= 12 && hour <= 23) ? "P.M." : "A.M.");
}

void	ft_takes_place(int hour)
{
	if (hour < 0 || hour > 23)
		return ;
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	printf("%d", (hour % 12 == 0) ? 12 : (hour % 12));
	printf(".00 %s", ft_xm(hour));
	hour++;
	printf(" AND %d", (hour % 12 == 0) ? 12 : (hour % 12));
	printf(".00 %s\n", ft_xm(hour));
}
