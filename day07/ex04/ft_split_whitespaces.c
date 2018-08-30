/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 04:57:37 by pcollio-          #+#    #+#             */
/*   Updated: 2018/08/30 07:52:45 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_whitespace(char c)
{
	return (c == '\n' || c == '\t' || c == ' ');
}

int		words(char *str)
{
	int word;
	int number;
	int i;

	word = 0;
	number = 0;
	i = 0;
	while (str[i])
	{
		if (!ft_whitespace(str[i]) && word == 0)
		{
			++number;
			word = 1;
		}
		else if (ft_whitespace(str[i]))
		{
			word = 0;
		}
		++i;
	}
	return (number);
}

int		length(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && !ft_whitespace(str[i]))
		++i;
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	if (i < n && src[i] == '\0')
	{
		while (dest[i] != '\0')
		{
			dest[i] = '\0';
			++i;
		}
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split_whitespaces(char *str)
{
	char	**array;
	int		word;
	int		i;
	int		j;
	int		len;

	array = (char **)malloc(words(str) * sizeof(char *) + 1);
	word = 0;
	j = 0;
	i = -1;
	while (str[++i])
	{
		if (!ft_whitespace(str[i]) && word == 0)
		{
			word = 1;
			len = length(&str[i]);
			array[j] = (char *)malloc((len + 1) * sizeof(char));
			array[j] = ft_strncpy(array[j], &str[i], len);
			++j;
		}
		else if (ft_whitespace(str[i]))
			word = 0;
	}
	array[j] = 0;
	return (array);
}
