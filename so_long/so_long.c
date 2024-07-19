/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:38:39 by yakhadad          #+#    #+#             */
/*   Updated: 2024/07/10 20:39:01 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_map(t_map *game, char *file)
{
	char	*lines;
	char	**map_copy;

	lines = ft_fill_map(game, file);
	ft_check_lines(lines);
	ft_split_map(game, lines);
	ft_check_walls(game);
	ft_check_elements(game);
	map_copy = ft_copy_map(game);
	ft_location(game, map_copy);
	ft_flood_fill(game, map_copy, game->x, game->y);
	ft_check_map(game, map_copy);
	ft_free_str(map_copy);
}

void	ft_create_image(t_map *game)
{
	int	x;
	int	y;

	game->character = mlx_xpm_file_to_image(game->mlx, "mage.xpm", &x, &y);
	game->wall = mlx_xpm_file_to_image(game->mlx, "wall.xpm", &x, &y);
	game->land = mlx_xpm_file_to_image(game->mlx, "land.xpm", &x, &y);
	game->ring = mlx_xpm_file_to_image(game->mlx, "ring.xpm", &x, &y);
	game->door = mlx_xpm_file_to_image(game->mlx, "open_exit.xpm", &x, &y);
	if(game->character == NULL || game->door == NULL
		|| game->ring == NULL || game->land == NULL || game->wall == NULL)
	{
		free(game->mlx);
		ft_free_str(game->map);
		ft_error("Error\nproblem while loading the image.");
	}

}

// void	ft_slot_fill(t_map *game, char slot, int x, int y)
// {

// }

void	ft_put_image(t_map *game)
{
	int	i;
	int	j;
	char slot;

	i = 0;
	while(i < game->width)
	{
		j = 0;
		while(j < game->height)
		{
			slot = game->map[j][i];
			if(slot == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, i * 50, j * 50);
			else if(slot == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->character, i * 50, j * 50);
			else if(slot == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->door, i * 50, j * 50);
			else if(slot == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->ring, i * 50, j * 50);
			else if(slot == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->land, i * 50, j * 50);
			j++;
		}
		i++;
	}
}

void	ft_exit_game(t_map *game)
{
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->land);
	mlx_destroy_image(game->mlx, game->character);
	mlx_destroy_image(game->mlx, game->door);
	mlx_destroy_image(game->mlx, game->ring);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free_str(game->map);
	exit(0);
}

void	ft_go_up(t_map *game)
{
	
}
int	ft_key_handle(int keycode, t_map *game)
{
	if(keycode == KEY_ESC)
		ft_exit_game(game);
	else if (keycode == KEY_UP)
		ft_go_up(game);
	return (0);
}

void	ft_mlx_handle(t_map *game)
{
	game->mlx = mlx_init();
	ft_create_image(game);
	game->win = mlx_new_window(game->mlx, 50 * game->width, 50 * game->height, "3amr 7mar");
	ft_put_image(game);
	mlx_key_hook(game->win, ft_key_handle, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_map	game;


	if (ac != 2)
		return (0);
	ft_check_ber(av[1]);
	ft_struct_fill(&game);
	ft_map(&game, av[1]);
	ft_mlx_handle(&game);
}
