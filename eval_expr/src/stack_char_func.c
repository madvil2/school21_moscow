/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_char_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 13:43:44 by pcollio-          #+#    #+#             */
/*   Updated: 2018/09/09 13:42:03 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	init_char(t_char *stk)
{
	stk->top = 0;
}

void	push_char(t_char *stk, char f)
{
	stk->elem[stk->top] = f;
	stk->top++;
}

char	pop_char(t_char *stk)
{
	char	elem;

	if ((stk->top) >= 0)
	{
		stk->top--;
		elem = stk->elem[stk->top];
		return (elem);
	}
	else
		return (0);
}

char	stktop_char(t_char *stk)
{
	if ((stk->top) >= 0)
		return (stk->elem[stk->top - 1]);
	else
		return (0);
}

char	isempty_char(t_char *stk)
{
	if ((stk->top) == 0)
		return (1);
	else
		return (0);
}
