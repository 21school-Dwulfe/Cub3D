#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	int g;

	if (fd < 0)
		return ;
	g = write(fd, &c, 1);
	(void)g;
}
