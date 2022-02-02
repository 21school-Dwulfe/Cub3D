#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*needle == 0)
		return ((char *) haystack);
	while ((i < len) && (haystack[i]) && (needle[j]))
	{
		if (haystack[i] == needle[j])
		{
			i++;
			j++;
			if (needle[j] == 0)
				return ((char *)(haystack + i - j));
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	return (NULL);
}
