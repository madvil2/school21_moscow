/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   own_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:04:31 by pcollio-          #+#    #+#             */
/*   Updated: 2018/09/08 19:40:53 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int		count_digits(char *str)
{
	int count;

	count = 0;
	while(*str)
	{
		if(*str >= '0' && *str <= '9')
			count++;
		str++;
	}
	return (count);
}

char	*ft_split_spaces(char *str)
{
	int j;
	char *s1;

	j = 0;
	s1 = malloc(sizeof(char) * ft_strlen(str) + 1);
	while(*str != '\0')
	{
		if(*str != ' ')
			s1[j++] = *str;
		str++;
	}
	s1[j] = '\0';
	return (s1);
}

int		count_chars(char *str)
{
	int count;

	count = 0;
	while(*str)
	{
		if((*str >= '0' && *str <= '9') || *str == ' ')
			str++;
		else
		{
			count++;
			str++;
		}
	}
	return (count);
}

int		ft_atoi(char *str, int index)
{
	int des;
	int num;

	des = 1;
	num = 0;
	while(str[index - 1] >= '0' && str[index - 1] <= '9')
	{
		num = (str[index--] - '0') * des + num;
		des = des * 10;
	}
	if(str[index] >= '0' && str[index] <= '9')
		num = (str[index--] - '0') * des + num;
	return (num);
}

void	calc(struct stack_int *stk_int, struct stack_char *stk_char)
{
	int a;
	int b;
	char op;

	a = stkTop_int(stk_int);
	pop_int(stk_int);
	b = stkTop_int(stk_int);
	pop_int(stk_int);
	op = stkTop_char(stk_char);
	pop_char(stk_char);

	if(op == '+')
		push_int(stk_int, a + b);
	else if(op == '-')
		push_int(stk_int, a - b);
	else if(op == '/')
		push_int(stk_int, a / b);
	else if(op == '*')
		push_int(stk_int, a * b);
	else if(op == '%')
		push_int(stk_int, a % b);
}

void	first_prior(struct stack_char *stk_char, struct stack_int *stk_int, char op)
{
	char sop; /* char in stack */
	
	sop = stkTop_char(stk_char);
	if (sop == '(')
		push_char(stk_char, op);
	else
	{
		calc(stk_int, stk_char);
		push_char(stk_char,op);
	}
}

void	second_prior(struct stack_char *stk_char, struct stack_int *stk_int, char op)
{
	char sop; /* char in stack */
	
	sop = stkTop_char(stk_char);
	if (sop == '+' || sop == '-' || sop == '(')
		push_char(stk_char, op);
	else
	{
		calc(stk_int, stk_char);
		push_char(stk_char,op);
	}
}

void	brackets(struct stack_char *stk_char, struct stack_int *stk_int, char op)
{
	if(op == '(')
		push_char(stk_char, op);
	else
	{
		while (stkTop_char(stk_char) != '(')
			calc(stk_int, stk_char);
		pop_char(stk_char);
	}
}