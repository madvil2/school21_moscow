/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <pcollio-@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 22:41:08 by pcollio-          #+#    #+#             */
/*   Updated: 2018/08/25 22:59:59 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int num)
{
	if (num <= 1)
		return (0);
	else if (num / 1 == num && num / num == 1)
		return (1);
	else
		return (0);
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb) == 1)
		return nb;
	else
		while (ft_is_prime(nb) == 1)
		{
			nb++;
		}
		return nb;
}

int main ()
{
	printf("%d\n", ft_find_next_prime(15));
}