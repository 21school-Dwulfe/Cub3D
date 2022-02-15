/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:28:39 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/05 20:20:47 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include "./libft/libft.h"
# ifdef __APPLE__
# include "./minilibx_opengl/mlx.h"
# elif __linux__
# include "./minilibx_linux/mlx.h"
# include "/usr/include/X11/X.h"
# endif
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

#endif