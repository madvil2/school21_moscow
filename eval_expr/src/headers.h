/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 09:19:57 by pcollio-          #+#    #+#             */
/*   Updated: 2018/09/08 19:31:32 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H

# define HEADERS_H

#include <stdlib.h>
#include <unistd.h>

struct stack_int {
	int		elem[50];
	int		top;
}			i_stack;

struct stack_char {
	char	elem[50];
	int		top;
}			c_stack;

void	init_char(struct stack_char *stk);
void	push_char(struct stack_char *stk, int f);
char	pop_char(struct stack_char *stk);
char	stkTop_char(struct stack_char *stk);
char	isempty_char(struct stack_char *stk);
void	init_int(struct stack_int *stk);
void	push_int(struct stack_int *stk, int f);
int		pop_int(struct stack_int *stk);
int		stkTop_int(struct stack_int *stk);
int		isempty_int(struct stack_int *stk);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
char	*ft_split_spaces(char *str);
int		ft_strlen(char *str);
int		count_digits(char *str);
int		count_chars(char *str);
int		ft_atoi(char *str, int index);
void	calc(struct stack_int *stk_int, struct stack_char *stk_char);
void	first_prior(struct stack_char *stk_char, struct stack_int *stk_int, char op);
void	second_prior(struct stack_char *stk_char, struct stack_int *stk_int, char op);
void	brackets(struct stack_char *stk_char, struct stack_int *stk_int, char op);
int		solve(char *str, struct stack_int *stk_int, struct stack_char *stk_char);
int		eval_expr(char *str);

#endif