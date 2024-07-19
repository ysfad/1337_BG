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
#include "../mlx_linux/mlx.h"
#include <math.h>

#define KEY_ESC 65307
#define KEY_UP 65362
#define KEY_DOWN 65364
#define KEY_LEFT 65361
#define KEY_RIGHT 65363

typedef struct s_map
{
    int     fd;
    int     width;
    int     height;
    int     coins;
    int     x;
    int     y;
    char    **map;
    void    *mlx;
    void    *win;
    void    *character;
    void    *door;
    void    *land;
    void    *ring;
    void    *wall;
}              t_map;

void	ft_error(char *s);
void	ft_free_str(char **str);
void    ft_element_error(t_map *game, int c, char e, char *str);
char	*ft_fill_map(t_map *game, char *file);
void	ft_split_map(t_map *game, char *tmp);
void	ft_check_ber(char *str);
void	ft_check_lines(char *tmp);
void	ft_check_walls(t_map *game);
void    ft_check_land(t_map *game);
void    ft_check_elements(t_map *game);
void	ft_struct_fill(t_map *game);
void	ft_check_map(t_map *game, char **map);
void	ft_flood_fill(t_map *game, char **map, int x, int y);
void	ft_check_land(t_map *game);
void    ft_location(t_map *game, char **map);
char	**ft_copy_map(t_map *game);

#endif
