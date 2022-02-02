#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (void *) malloc(count * size);
	if (!res)
		return (NULL);
	while (i < (count * size))
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}
