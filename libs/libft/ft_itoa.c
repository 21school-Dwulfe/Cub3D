#include "libft.h"

static long	len_number(long n)
{
	long	i;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
	{
		i += 1;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	len;
	long	i;

	i = n;
	len = len_number(i);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (i == 0)
		str[0] = '0';
	if (i < 0)
	{
		str[0] = '-';
		i = -i;
	}
	len = len - 1;
	while (i > 0)
	{
		str[len] = (i % 10) + 48;
		i = i / 10;
		len--;
	}
	return (str);
}
