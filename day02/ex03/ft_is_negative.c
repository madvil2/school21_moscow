/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 20:32:44 by pcollio-          #+#    #+#             */
/*   Updated: 2018/08/23 20:59:04 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(int c);

void	ft_is_negative(int n)
{
	if (n >= 0)
	{
		ft_putchar('N');
	}
	else
	{
		ft_putchar('P');
	}
}
