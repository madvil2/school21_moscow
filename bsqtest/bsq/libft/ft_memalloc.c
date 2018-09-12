#include "../include/headers.h"

void	ft_bzero(void *s, size_t n)
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

void	*ft_memalloc(size_t size)
{
	void	*buf;

	buf = (void *)malloc(size);
	if (buf != NULL)
		ft_bzero(buf, size);
	return (buf);
}