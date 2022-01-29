/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:04:51 by dwulfe            #+#    #+#             */
/*   Updated: 2021/11/30 18:04:51 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_output(int n, int size, int fd)
{
	char	c;

	while (size)
	{
		c = (n / size) + '0';
		write(fd, &c, 1);
		n %= size;
		size /= 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	temp;
	int	size;

	size = 1;
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			write(fd, "2", 1);
			n = 147483648;
		}
		else
			n = -n;
	}
	temp = n / 10;
	while (temp)
	{
		size *= 10;
		temp /= 10;
	}
	ft_output(n, size, fd);
}
