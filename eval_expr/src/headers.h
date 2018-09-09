/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 09:19:57 by pcollio-          #+#    #+#             */
/*   Updated: 2018/09/09 13:51:34 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

# include <stdlib.h>
# include <unistd.h>

# define NMAX 50

typedef struct	s_int {
	int			elem[NMAX];
	int			top;
}				t_int;

typedef struct	s_char {
	char		elem[NMAX];
	int			top;
}				t_char;

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);
int				count_digits(char *str);
int				count_chars(char *str);
int				ft_atoi(char *str, int i);
void			calc(t_int *stk_i, t_char *stk_c);
void			first_prior(t_int *stk_i, t_char *stk_c, char op);
void			second_prior(t_int *stk_i, t_char *stk_c, char op);
void			brackets(t_int *stk_i, t_char *stk_c, char op);
void			init_char(t_char *stk);
void			push_char(t_char *stk, char f);
char			pop_char(t_char *stk);
char			stktop_char(t_char *stk);
char			isempty_char(t_char *stk);
void			init_int(t_int *stk);
void			push_int(t_int *stk, int f);
int				pop_int(t_int *stk);
int				stktop_int(t_int *stk);
int				isempty_int(t_int *stk);
int				solve(char *str, t_int *stk_i, t_char *stk_c);

#endif
