/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:39:07 by yakhadad          #+#    #+#             */
/*   Updated: 2024/07/10 20:39:28 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
#define SO_LONG_H

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <math.h>

typedef struct s_map
{
    int     fd;
    size_t     width;
    size_t     hight;
    char    **arr;
}              t_map;


#endif
