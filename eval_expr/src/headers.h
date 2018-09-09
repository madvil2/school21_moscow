/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 09:19:57 by pcollio-          #+#    #+#             */
/*   Updated: 2018/09/09 10:31:56 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H

# define HEADERS_H

#include <stdlib.h>
#include <unistd.h>
#define NMAX 50

struct		stack_int {
	int		elem[NMAX];
	int		top;
};

struct		stack_char {
	char	elem[NMAX];
    int		top;
};

void    ft_putchar(char c);
void    ft_putnbr(int n);
void    ft_putstr(char *str);
char    *delete_tabs(char *str);
int     count_digits(char *str);
int     count_chars(char *c);

void    init(struct stack_int *stk);
void    push(struct stack_int *stk, int f);
int     pop(struct stack_int *stk);
int     stktop(struct stack_int *stk);
int     isempty(struct stack_int *stk);

void    init_c(struct stack_char *stk);
void    push_c(struct stack_char *stk, char f);
char    pop_c(struct stack_char *stk);
char    stktop_c(struct stack_char *stk);
char    isempty_c(struct stack_char *stk);

int     ft_atoi(char *str, int i);
int     eval_expr(char *str);
void    calc(struct stack_int *stk_i, struct stack_char *stk_c);
void    f_prioritet(struct stack_int *stk_i, struct stack_char *stk_c, char op);
void    s_prioritet(struct stack_int *stk_i, struct stack_char *stk_c, char op);
void    brackets(struct stack_int *stk_i, struct stack_char *stk_c, char op);
int     solve(char *str, struct stack_int *stk_i, struct stack_char *stk_c);

#endif
