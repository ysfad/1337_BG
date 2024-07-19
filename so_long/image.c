/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 08:38:27 by yakhadad          #+#    #+#             */
/*   Updated: 2024/07/19 08:38:41 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_create_image(t_map *game)
{
	int	x;
	int	y;

	game->character = mlx_xpm_file_to_image(game->mlx, "mage.xpm", &x, &y);
	game->wall = mlx_xpm_file_to_image(game->mlx, "wall.xpm", &x, &y);
	game->land = mlx_xpm_file_to_image(game->mlx, "land.xpm", &x, &y);
	game->ring = mlx_xpm_file_to_image(game->mlx, "ring.xpm", &x, &y);
	game->door = mlx_xpm_file_to_image(game->mlx, "closed_exit.xpm", &x, &y);
	game->o_door = mlx_xpm_file_to_image(game->mlx, "open_exit.xpm", &x, &y);
	if (game->character == NULL || game->door == NULL || game->ring == NULL
		|| game->land == NULL || game->wall == NULL || game->o_door == NULL)
		ft_exit_game(game);
}

void	ft_image_to_window(t_map *game, char slot, int x, int y)
{
	if (slot == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall, x, y);
	else if (slot == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->character, x, y);
	else if (slot == 'E')
	{
		if (game->coins > 0)
			mlx_put_image_to_window(game->mlx, game->win, game->door, x, y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->o_door, x, y);
	}
	else if (slot == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->ring, x, y);
	else if (slot == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->land, x, y);
}

void	ft_put_image(t_map *game)
{
	int		i;
	int		j;
	char	slot;

	i = 0;
	while (i < game->width)
	{
		j = 0;
		while (j < game->height)
		{
			slot = game->map[j][i];
			ft_image_to_window(game, slot, i * 50, j * 50);
			j++;
		}
		i++;
	}
}
