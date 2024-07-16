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
	ft_flood_fill(game, map_copy, game->player[0], game->player[1]);
	ft_check_map(game, map_copy);
	ft_free_str(map_copy);
}

int	main(int ac, char **av)
{
	t_map	game;
	void	*mlx;
	void	*window;

	if (ac != 2)
		return (0);
	ft_check_ber(av[1]);
	ft_struct_fill(&game);
	ft_map(&game, av[1]);
	mlx = mlx_init();
	window = mlx_new_window(mlx, 800, 600, "3amr 7mar");
    mlx_loop(mlx);
}
