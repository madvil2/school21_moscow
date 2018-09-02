/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 05:12:28 by pcollio-          #+#    #+#             */
/*   Updated: 2018/08/31 05:24:05 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PERSO_H
# define FT_PERSO_H
#define SAVE_THE_WORLD "Savetheworld"

typedef struct s_perso	t_perso;

struct	s_perso
{
	char	*name;
	double	life;
	int		age;
	char	profession;
};

#endif
