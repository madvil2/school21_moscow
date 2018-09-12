#include "../include/headers.h"

char	*ft_strjoin(char const *s1, char const *s2)
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