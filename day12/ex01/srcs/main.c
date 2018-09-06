/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 20:47:38 by pcollio-          #+#    #+#             */
/*   Updated: 2018/09/06 21:09:46 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while(s[i])
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

int		ft_error(int argc)
{
	char c;

	if (argc == 1)
	{
		while (read(0, &c, 1))
			write(1, &c, 1);
		return (1);
	}
	return (0);
}

void	ft_bad_name(char *str)
{
	ft_putstr("cat: ");
	ft_putstr(str);
	ft_putstr(": No such file or directory\n");
}

void	ft_folder_name(char *str)
{
	ft_putstr("cat: ");
	ft_putstr(str);
	ft_putstr(": Is a directory\n");
}

int		main(int argc, char **argv)
{
	int		file;
	int		i;
	int		rd;
	char	buf[2];

	if (ft_error(argc))
		return (0);
	i = 1;
	rd = 1;
	while (i < argc)
	{
		file = open(argv[i], O_RDONLY);
		if (file < 0)
			ft_bad_name(argv[i]);
		else if (read(file, 0, 0) < 0)
			ft_folder_name(argv[i]);
		else
			while (rd)
			{
				rd = read(file, buf, 1);
				buf[rd] = '\0';
				ft_putstr(buf);
			}
		close(file);
		i++;
	}
	return (errno);
}