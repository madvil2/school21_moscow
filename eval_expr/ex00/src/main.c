/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 09:19:54 by pcollio-          #+#    #+#             */
/*   Updated: 2018/09/09 18:01:22 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	eval_expr(char *str)
{
	t_int	*stk_i;
	t_char	*stk_c;

	stk_i = malloc(sizeof(t_int));
	stk_c = malloc(sizeof(t_char));
	init_int(stk_i);
	init_char(stk_c);
	return (solve(str, stk_i, stk_c));
}

int	solve(char *str, t_int *stk_i, t_char *stk_c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i + 1] >= '0' && str[i + 1] <= '9')
				i++;
			push_int(stk_i, ft_atoi(str, i));
		}
		else if (str[i] == '+' || str[i] == '-')
			first_prior(stk_i, stk_c, str[i]);
		else if (str[i] == '*' || str[i] == '/' || str[i] == '%')
			second_prior(stk_i, stk_c, str[i]);
		else if (str[i] == '(' || str[i] == ')')
			brackets(stk_i, stk_c, str[i]);
		i++;
	}
	while (isempty_char(stk_c) == 0)
		calc(stk_i, stk_c);
	return (stktop_int(stk_i));
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
