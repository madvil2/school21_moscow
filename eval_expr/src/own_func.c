/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   own_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:04:31 by pcollio-          #+#    #+#             */
/*   Updated: 2018/09/09 13:41:29 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int		ft_atoi(char *str, int i)
{
	int des;
	int num;

	des = 1;
	num = 0;
	while (str[i - 1] >= '0' && str[i - 1] <= '9')
	{
		num = (str[i--] - '0') * des + num;
		des = des * 10;
	}
	if (str[i] >= '0' && str[i] <= '9')
		num = (str[i] - '0') * des + num;
	return (num);
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
	char sop;

	sop = stktop_char(stk_c);
	if (sop == '(' || isempty_char(stk_c) == 1)
		push_char(stk_c, op);
	else
	{
		while (sop == '*' || sop == '/' || sop == '+'
		|| sop == '-' || sop == '%')
		{
			calc(stk_i, stk_c);
			sop = stktop_char(stk_c);
		}
		push_char(stk_c, op);
	}
}

void	second_prior(t_int *stk_i, t_char *stk_c, char op)
{
	char sop;

	sop = stktop_char(stk_c);
	if (sop == '+' || sop == '-' || sop == '(' || isempty_char(stk_c) == 1)
		push_char(stk_c, op);
	else
	{
		while (sop == '*' || sop == '/' || sop == '%')
		{
			calc(stk_i, stk_c);
			sop = stktop_char(stk_c);
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
