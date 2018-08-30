/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 02:47:38 by pcollio-          #+#    #+#             */
/*   Updated: 2018/08/30 04:58:58 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int len;
	len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_concat_params(int argc, char **argv)
{
	char *param;
	int i;
	int j;
	int k;
	int size;

	i = 1;
	size = 0;
	while (i < argc)
		size = size + ft_strlen(argv[i++]);
	param = (char *)malloc((size) * sizeof(char *));
	k = 0;
	i = 1;
	while(i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
			param[k++] = argv[i][j++];
		if (i == argc - 1)
			param[k++] = '\0';
		else
			param[k++] = '\n';
		i++;
	}
	return (param);
}
