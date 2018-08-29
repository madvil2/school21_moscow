/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:35:48 by pcollio-          #+#    #+#             */
/*   Updated: 2018/08/29 18:58:30 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
		ft_putchar(*str++);
}

void	ft_swap(char *a, char *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		s_bubblesort(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (i < argc - 1)
	{
		while (j < argc - i - 1)
		{
			if(argv[i] > argv[j + 1])
				ft_swap(&argv[j], &argv[j+1]);
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		s_bubblesort(i, argv[i]);
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
