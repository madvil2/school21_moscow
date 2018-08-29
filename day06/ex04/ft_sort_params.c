/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:35:48 by pcollio-          #+#    #+#             */
/*   Updated: 2018/08/29 23:09:43 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0' && s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_params(char *c)
{
	while (*c)
	{
		ft_putchar(*c);
		c++;
	}
}

int		main(int argc, char *argv[])
{
	int		i;
	char	*c;

	i = 2;
	argc = 1;
	while (argv[argc])
	{
		while (argv[i])
		{
			if (ft_strcmp(argv[argc], argv[i]) > 0)
			{
				c = argv[argc];
				argv[argc] = argv[i];
				argv[i] = c;
			}
			i++;
		}
		ft_sort_params(argv[argc]);
		ft_putchar('\n');
		argc++;
		i = argc + 1;
	}
	return (0);
}
