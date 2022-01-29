/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:40:45 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/12/19 13:40:49 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_read(int fd, char *buf, int *ret)
{
	return (*ret = (int) read(fd, buf, FOPEN_MAX));
}

void	ft_freeshka(char **string)
{
	if (string && *string != NULL)
	{
		free(*string);
		*string = NULL;
	}
}

static int	ft_make_line(char **ost, char **line)
{
	char	*ptr_n;
	char	*tmp;

	ptr_n = ft_strchr(*ost, '\n');
	if (ptr_n)
	{
		*ptr_n = '\0';
		tmp = *ost;
		*line = ft_strdup(tmp);
		ptr_n++;
		*ost = ft_strdup(ptr_n);
		ft_freeshka(&tmp);
	}
	else
	{
		*line = ft_strdup(*ost);
		ft_freeshka(ost);
		return (0);
	}
	return (1);
}

static int	ft_out(char **ost, char **line, int ret)
{
	if (ret == 0)
	{
		if (ost)
			return (ft_make_line(ost, line));
		else
			*line = NULL;
		return (0);
	}
	else
		return (ft_make_line(ost, line));
}

int	get_next_line(int fd, char **line, int ret)
{
	static char		*ost;
	char			*buf;
	char			*tmp;

	buf = malloc(sizeof(char) * (FOPEN_MAX + 1));
	if (!buf)
		ft_error(MALLOC_ERROR);
	while (ft_read(fd, buf, &ret))
	{
		buf[ret] = '\0';
		if (!ost)
			ost = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(ost, buf);
			ft_freeshka(&ost);
			ost = tmp;
			tmp = NULL;
		}
		if (ft_strchr(ost, '\n'))
			break ;
	}
	ft_freeshka(&buf);
	return (ft_out(&ost, line, ret));
}
