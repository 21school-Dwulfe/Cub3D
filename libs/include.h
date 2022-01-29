/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:28:39 by dwulfe            #+#    #+#             */
/*   Updated: 2022/01/29 17:39:26 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# ifdef __APPLE__
# include "./minilibx_mms/mlx.h"
# elif __linux__
# include "./minilibx-linux-master/mlx.h"
# endif

# include "./libft/libft.h"

#endif