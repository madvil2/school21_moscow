/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 09:48:46 by pcollio-          #+#    #+#             */
/*   Updated: 2018/09/09 18:14:31 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
}

void	ft_putnbr(int nb)
{
	int num;

	num = nb;
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num > 9)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + 48);
}

int		count_digits(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			count++;
		str++;
	}
	return (count);
}

int		count_chars(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9') && (*str != ' '))
			count++;
		str++;
	}
	return (count);
}
