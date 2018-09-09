/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 09:48:46 by pcollio-          #+#    #+#             */
/*   Updated: 2018/09/08 20:01:40 by pcollio-         ###   ########.fr       */
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

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n >= 10)
			ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
}

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while(*str)
	{
		if (*str != ' ')
			len++;
		str++;
	}
	return (len);
}
