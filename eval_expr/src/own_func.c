/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   own_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:04:31 by pcollio-          #+#    #+#             */
/*   Updated: 2018/09/09 11:41:41 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

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

char	*delete_tabs(char *str)
{
	char *a;
	int n;
	int i;

	n = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			n++;
		i++;
	}
	a = malloc(sizeof(char) * n + 1);
	i = 0;
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
			a[i++] = *str;
		str++;
	}
	a[i] = '\0';
	return (a);
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

int		ft_atoi(char *str, int i)
{
	int des;
	int n;

	des = 1;
	n = 0;

	while (str[i-1] >= '0' && str[i-1] <= '9')
	{
		n = (str[i] - '0') * des + n;
		i--;
		des = des * 10;
	}
	if (str[i] >= '0' && str[i] <= '9')
		n = (str[i] - '0') * des + n;
	return (n);
}

void	calc(struct stack_int *stk_i, struct stack_char *stk_c)
{
	int a;
	int b;
	char op;

	a = stktop(stk_i);
	pop(stk_i);
	b = stktop(stk_i);
	pop(stk_i);
	op = stktop_c(stk_c);
	pop_c(stk_c);

	if (op == '/')
		push(stk_i, (b / a));
	else if (op == '*')
		push(stk_i, (b * a));
	else if (op == '+')
		push(stk_i, (b + a));
	else if (op == '-')
		push(stk_i, (b - a));
	else if (op == '%')
		push(stk_i, (b % a));
}

void	f_prioritet(struct stack_int *stk_i, struct stack_char *stk_c, char op)
{
	char sop;

	sop = stktop_c(stk_c);
	if (sop == '(' || isempty_c(stk_c) == 1)
		push_c(stk_c, op);
	else 
	{
		calc(stk_i, stk_c);
		push_c(stk_c, op);
	}
}

void	s_prioritet(struct stack_int *stk_i, struct stack_char *stk_c, char op)
{
	char sop;

	sop = stktop_c(stk_c);
	if (sop == '+' || sop == '-' || sop == '(' || isempty_c(stk_c) == 1)
		push_c(stk_c, op);
	else
	{
		calc(stk_i, stk_c);
		push_c(stk_c, op);
	}
}

void	brackets(struct stack_int *stk_i, struct stack_char *stk_c, char op)
{
	if (op == '(')
		push_c(stk_c, op);
	else
	{
		while (stktop_c(stk_c) != '(')
			calc(stk_i, stk_c);
		pop_c(stk_c);
	}
}