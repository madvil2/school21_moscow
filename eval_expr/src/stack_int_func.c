/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_int_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 13:09:51 by pcollio-          #+#    #+#             */
/*   Updated: 2018/09/09 10:16:21 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	init(struct stack_int *stk)
{
	stk->top = 0;
}

void	push(struct stack_int *stk, int f)
{
	stk->elem[stk->top] = f;
	stk->top++;
}

int		pop(struct stack_int *stk)
{
	int	elem;
	if ((stk->top) >= 0) {
		stk->top--;
		elem = stk->elem[stk->top];
		return (elem);
	}
	else
		return (0);
}

int		stktop(struct stack_int *stk)
{
	if ((stk->top) >= 0)
		return (stk->elem[stk->top-1]);
	else
		return (0);
}

int		isempty(struct stack_int *stk)
{
	if((stk->top) == 0)
		return (1);
	else
		return (0);
}
