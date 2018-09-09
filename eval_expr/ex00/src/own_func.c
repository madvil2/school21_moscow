/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   own_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:04:31 by pcollio-          #+#    #+#             */
/*   Updated: 2018/09/09 18:01:58 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int		ft_atoi(char *str, int i)
{
	int des;
	int n;

	des = 1;
	n = 0;
	while (str[i - 1] >= '0' && str[i - 1] <= '9')
	{
		n = (str[i] - '0') * des + n;
		i--;
		des = des * 10;
	}
	if (str[i] >= '0' && str[i] <= '9')
		n = (str[i] - '0') * des + n;
	return (n);
}

void	calc(t_int *stk_i, t_char *stk_c)
{
	int		a;
	int		b;
	char	op;

	a = stktop_int(stk_i);
	pop_int(stk_i);
	b = stktop_int(stk_i);
	pop_int(stk_i);
	op = stktop_char(stk_c);
	pop_char(stk_c);
	if (op == '/')
		push_int(stk_i, (b / a));
	else if (op == '*')
		push_int(stk_i, (b * a));
	else if (op == '+')
		push_int(stk_i, (b + a));
	else if (op == '-')
		push_int(stk_i, (b - a));
	else if (op == '%')
		push_int(stk_i, (b % a));
}

void	first_prior(t_int *stk_i, t_char *stk_c, char op)
{
	char s_op;

	s_op = stktop_char(stk_c);
	if (s_op == '(' || isempty_char(stk_c) == 1)
		push_char(stk_c, op);
	else
	{
		while (s_op == '+' || s_op == '-' || s_op == '*' || s_op == '/'
				|| s_op == '%')
		{
			calc(stk_i, stk_c);
			s_op = stktop_char(stk_c);
		}
		push_char(stk_c, op);
	}
}

void	second_prior(t_int *stk_i, t_char *stk_c, char op)
{
	char s_op;

	s_op = stktop_char(stk_c);
	if (s_op == '+' || s_op == '-' || s_op == '(' || isempty_char(stk_c) == 1)
		push_char(stk_c, op);
	else
	{
		while (s_op == '*' || s_op == '/' || s_op == '%')
		{
			calc(stk_i, stk_c);
			s_op = stktop_char(stk_c);
		}
		push_char(stk_c, op);
	}
}

void	brackets(t_int *stk_i, t_char *stk_c, char op)
{
	if (op == '(')
		push_char(stk_c, op);
	else
	{
		while (stktop_char(stk_c) != '(')
			calc(stk_i, stk_c);
		pop_char(stk_c);
	}
}
