/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 23:39:20 by pcollio-          #+#    #+#             */
/*   Updated: 2018/09/06 23:39:21 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlen(const char *s)
{
	size_t		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

int				ft_putstr(char const *s)
{
	if (!s)
		return (0);
	return (write(1, s, ft_strlen(s)));
}

int				ft_atoi(const char *str)
{
	short			i;
	unsigned long	result;
	short			minus;

	i = 0;
	result = 0;
	minus = 1;
	while ((str[i] >= '\a' && str[i] <= '\r') || str[i] == 32)
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	result = result * minus;
	return ((int)result);
}
