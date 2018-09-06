/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 01:11:29 by pcollio-          #+#    #+#             */
/*   Updated: 2018/09/06 21:38:48 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#define BUFF_SIZE 4096

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_putstr(char const *s)
{
	if (s)
		return (write(1, s, ft_strlen(s)));
	else
		return (0);
}

int		main(int ac, char **av)
{
	int		file;
	int		rd;
	char	buf[BUFF_SIZE + 1];

	rd = 1;
	if (ac == 1)
		ft_putstr("File name missing.\n");
	else if (ac > 2)
		ft_putstr("Too many arguments.\n");
	else
	{
		file = open(av[1], O_RDONLY);
		if (file != -1)
		{
			while (rd)
			{
				rd = read(file, buf, BUFF_SIZE);
				buf[rd] = '\0';
				ft_putstr(buf);
			}
		}
		close(file);
	}
	return (0);
}
