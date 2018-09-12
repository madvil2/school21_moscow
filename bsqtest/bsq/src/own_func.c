#include "../include/headers.h"

int		str_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int		str_len2(char **str)
{
	int i;

	i = 0;
	while (str[0][i] != '\0')
		i++;
	return (i);
}

int		count_lines(char *str)
{
	int count;
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	i = 0;
	return (count);
}

int		ft_not_atoi(char *str)
{
	int des;
	int n;

	des = 1;
	n = 0;
	while (*(str - 1) >= '0' && *(str - 1) <= '9')
	{
		n = (*str - '0') * des + n;
		des = des * 10;
	}
	if (*str >= '0' && *str <= '9')
		n = (*str - '0') * des + n;
	return (n);
}