/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:24:28 by yakhadad          #+#    #+#             */
/*   Updated: 2024/07/13 14:27:22 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_error(char *s)
{
	ft_printf("ERROR\n");
	ft_printf("%s\n", s);
	exit(1);
}

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

void	ft_element_error(t_map *game, int c, char e, char *str)
{
	if (c == 0 && e == 'C')
	{
		ft_free_str(game->map);
		ft_error("there must be at least 1 coin (C).");
	}
	if (c != 1 && e != 'C')
	{
		ft_free_str(game->map);
		ft_printf("ERROR\nthere must be 1 %s (%c).\n", str, e);
		exit(1);
	}
}

void	ft_destroy(t_map *game)
{
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	else
		free(game->wall);
	if (game->land)
		mlx_destroy_image(game->mlx, game->land);
	else
		free(game->land);
	if (game->door)
		mlx_destroy_image(game->mlx, game->door);
	else
		free(game->door);
	if (game->o_door)
		mlx_destroy_image(game->mlx, game->o_door);
	else
		free(game->o_door);
	if (game->character)
		mlx_destroy_image(game->mlx, game->character);
	else
		free(game->character);
	if (game->ring)
		mlx_destroy_image(game->mlx, game->ring);
	else
		free(game->ring);
}

int	ft_exit_game(t_map *game)
{
	int	cas;

	cas = 0;
	if (game->character == NULL || game->door == NULL || game->ring == NULL
		|| game->land == NULL || game->wall == NULL || game->o_door == NULL)
	{
		ft_printf("Error\nProblem with the images.\n");
		cas = 1;
	}
	else if (game->map[game->y][game->x] != 'E')
		ft_printf("YOU LOST THE GAME!\n");
	else
	{
		ft_printf("Steps Taken: %i\n", game->steps);
		ft_printf("YOU WON!!!\n");
	}
	ft_destroy(game);
	if (cas != 1)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free_str(game->map);
	if (cas != 0)
		exit(1);
	exit(0);
}
