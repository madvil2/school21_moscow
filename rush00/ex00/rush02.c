/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 19:45:02 by pcollio-          #+#    #+#             */
/*   Updated: 2018/08/26 23:04:50 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LEFT_TOP_CHAR			'A'
#define RIGHT_TOP_CHAR			'A'
#define LEFT_BOT_CHAR			'C'
#define RIGHT_BOT_CHAR			'C'
#define TOP_BOT_SIDE_CHAR		'B'
#define LEFT_RIGHT_SIDE_CHAR	'B'

int		ft_putchar(char c);

void	create(int x, int y, int a, int b)
{
	if (a == 1 && b == 1)
		ft_putchar(LEFT_TOP_CHAR);
	else if (a == 1 && b == x)
		ft_putchar(RIGHT_TOP_CHAR);
	else if (a == y && b == 1)
		ft_putchar(LEFT_BOT_CHAR);
	else if (a == y && b == x)
		ft_putchar(RIGHT_BOT_CHAR);
	else if (a == 1 || a == y)
		ft_putchar(TOP_BOT_SIDE_CHAR);
	else if (b == 1 || b == x)
		ft_putchar(LEFT_RIGHT_SIDE_CHAR);
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int a;
	int b;

	a = 0;
	if (x <= 0 || y <= 0)
		return ;
	else
	{
		while (++a <= y)
		{
			b = 0;
			while (++b <= x)
			{
				create(x, y, a, b);
			}
			ft_putchar('\n');
		}
	}
}
