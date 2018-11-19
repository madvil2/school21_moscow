/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 23:39:12 by pcollio-          #+#    #+#             */
/*   Updated: 2018/09/12 23:39:13 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/headers.h"

void		ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = n % sizeof(size_t);
	while (i)
	{
		--i;
		((unsigned char *)s)[i] = 0;
	}
	n /= sizeof(size_t);
	while (n)
	{
		--n;
		((size_t *)s)[n] = 0;
	}
}

void		*ft_memalloc(size_t size)
{
	void	*buf;

	buf = (void *)malloc(size);
	if (buf != NULL)
		ft_bzero(buf, size);
	return (buf);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	buf = (char *)malloc(sizeof(*buf) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (buf == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		buf[i++] = s1[j++];
	j = 0;
	while (s2[j])
		buf[i++] = s2[j++];
	buf[i] = '\0';
	return (buf);
}

char		*ft_strsub(char const *s, size_t start, size_t len)
{
	char	*buf;
	size_t	i;

	if (s == NULL)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		buf[i++] = s[start++];
	buf[i] = '\0';
	return (buf);
}
