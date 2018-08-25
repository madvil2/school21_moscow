/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 23:45:27 by pcollio-          #+#    #+#             */
/*   Updated: 2018/08/25 23:45:31 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int num)
{
	int i;

	if ((num < 2 || num % 2 == 0) && num != 2)
	{
		return (0);
	}
	i = 1;
	while (i * i <= num && i * i > 0)
	{
		if (num % (i * 2 + 1) == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb) == 1)
		return nb;
	else
		return 0;
}
