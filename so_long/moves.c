/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 08:33:51 by yakhadad          #+#    #+#             */
/*   Updated: 2024/07/19 08:34:10 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_go_up(t_map *game, int x, int y)
{
	int	cas;

	cas = 0;
	if (game->map[y - 1][x] == '1' || (game->map[y - 1][x] == 'E'
			&& game->coins > 0))
		cas = 1;
	if (game->map[y - 1][x] == '0' || game->map[y - 1][x] == 'C')
	{
		if (game->map[y - 1][x] == 'C')
			game->coins--;
		game->map[y][x] = '0';
		game->map[y - 1][x] = 'P';
		ft_put_image(game);
		game->y--;
	}
	else if (game->map[y - 1][x] == 'E' && game->coins == 0)
	{
		game->y--;
		ft_exit_game(game);
	}
	if (cas == 0)
	{
		game->steps++;
		ft_printf("Steps Taken: %i\n", game->steps);
	}
}

void	ft_go_down(t_map *game, int x, int y)
{
	int	cas;

	cas = 0;
	if (game->map[y + 1][x] == '1' || (game->map[y + 1][x] == 'E'
			&& game->coins > 0))
		cas = 1;
	if (game->map[y + 1][x] == '0' || game->map[y + 1][x] == 'C')
	{
		if (game->map[y + 1][x] == 'C')
			game->coins--;
		game->map[y][x] = '0';
		game->map[y + 1][x] = 'P';
		ft_put_image(game);
		game->y++;
	}
	else if (game->map[y + 1][x] == 'E' && game->coins == 0)
	{
		game->y++;
		ft_exit_game(game);
	}
	if (cas == 0)
	{
		game->steps++;
		ft_printf("Steps Taken: %i\n", game->steps);
	}
}

void	ft_go_left(t_map *game, int x, int y)
{
	int	cas;

	cas = 0;
	if (game->map[y][x - 1] == '1' || (game->map[y][x - 1] == 'E'
			&& game->coins > 0))
		cas = 1;
	if (game->map[y][x - 1] == '0' || game->map[y][x - 1] == 'C')
	{
		if (game->map[y][x - 1] == 'C')
			game->coins--;
		game->map[y][x] = '0';
		game->map[y][x - 1] = 'P';
		ft_put_image(game);
		game->x--;
	}
	else if (game->map[y][x - 1] == 'E' && game->coins == 0)
	{
		game->x--;
		ft_exit_game(game);
	}
	if (cas == 0)
	{
		game->steps++;
		ft_printf("Steps Taken: %i\n", game->steps);
	}
}

void	ft_go_right(t_map *game, int x, int y)
{
	int	cas;

	cas = 0;
	if (game->map[y][x + 1] == '1' || (game->map[y][x + 1] == 'E'
			&& game->coins > 0))
		cas = 1;
	if (game->map[y][x + 1] == '0' || game->map[y][x + 1] == 'C')
	{
		if (game->map[y][x + 1] == 'C')
			game->coins--;
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'P';
		ft_put_image(game);
		game->x++;
	}
	else if (game->map[y][x + 1] == 'E' && game->coins == 0)
	{
		game->x++;
		ft_exit_game(game);
	}
	if (cas == 0)
	{
		game->steps++;
		ft_printf("Steps Taken: %i\n", game->steps);
	}
}
