#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	count;
	char	*str;

	i = 0;
	count = 0;
	if (!s)
		return (NULL);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (i >= start && count < len)
		{
			str[count] = s[i];
			count++;
		}
		i++;
	}
	str[count] = '\0';
	return (str);
}
