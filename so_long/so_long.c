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

int	ft_key_handle(int keycode, t_map *game)
{
	if (keycode == KEY_ESC)
		ft_exit_game(game);
	else if (keycode == KEY_UP || keycode == KEY_W)
		ft_go_up(game, game->x, game->y);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		ft_go_down(game, game->x, game->y);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		ft_go_left(game, game->x, game->y);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		ft_go_right(game, game->x, game->y);
	return (0);
}

void	ft_mlx_handle(t_map *game)
{
	game->mlx = mlx_init();
	ft_create_image(game);
	game->win = mlx_new_window(game->mlx, 50 * game->width, 50 * game->height,
			"Mage Of The Rings");
	ft_put_image(game);
	ft_printf("Steps Taken: %i\n", game->steps);
	mlx_key_hook(game->win, ft_key_handle, game);
	mlx_hook(game->win, 17, 0, ft_exit_game, game);
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
