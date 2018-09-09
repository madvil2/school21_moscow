/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_int_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 13:09:51 by pcollio-          #+#    #+#             */
/*   Updated: 2018/09/09 13:42:35 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	init_int(t_int *stk)
{
	stk->top = 0;
}

void	push_int(t_int *stk, int f)
{
	stk->elem[stk->top] = f;
	stk->top++;
}

int		pop_int(t_int *stk)
{
	int elem;

	if ((stk->top) >= 0)
	{
		stk->top--;
		elem = stk->elem[stk->top];
		return (elem);
	}
	else
		return (0);
}

int		stktop_int(t_int *stk)
{
	if ((stk->top) >= 0)
		return (stk->elem[stk->top - 1]);
	else
		return (0);
}

int		isempty_int(t_int *stk)
{
	if ((stk->top) == 0)
		return (1);
	else
		return (0);
}
