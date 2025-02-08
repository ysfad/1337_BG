/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 04:56:32 by yakhadad          #+#    #+#             */
/*   Updated: 2024/07/15 04:56:51 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char	**ft_copy_map(t_map *game)
{
	int		i;
	char	**copy_map;

	i = 0;
	copy_map = (char **)malloc((game->height + 1) * sizeof(char *));
	while (game->map[i])
	{
		copy_map[i] = ft_strdup(game->map[i]);
		if (copy_map[i] == NULL)
		{
			ft_free_str(copy_map);
			ft_error("problem while allocating the map copy.");
		}
		i++;
	}
	copy_map[i] = NULL;
	return (copy_map);
}

void	ft_location(t_map *game, char **map)
{
	int	i;
	int	j;

	i = 1;
	while (i < game->height - 1)
	{
		j = 1;
		while (j < game->width - 1)
		{
			if (map[i][j] == 'P')
			{
				game->x = j;
				game->y = i;
				break ;
			}
			j++;
		}
		if (map[i][j] == 'P')
			break ;
		i++;
	}
}

void	ft_check_land(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1'
				&& game->map[i][j] != 'C' && game->map[i][j] != 'P'
				&& game->map[i][j] != 'E')
			{
				ft_free_str(game->map);
				ft_printf("Error\nwrong element inside the map.\n");
				ft_printf("Elements: 1, 0, C, P, E.\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	ft_flood_fill(t_map *game, char **map, int x, int y)
{
	if (x >= game->width - 1 || x <= 0 || y >= game->height - 1 || y <= 0)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'S' || map[y][x] == 'X')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'X';
		return ;
	}
	map[y][x] = 'S';
	ft_flood_fill(game, map, x + 1, y);
	ft_flood_fill(game, map, x - 1, y);
	ft_flood_fill(game, map, x, y + 1);
	ft_flood_fill(game, map, x, y - 1);
}

void	ft_check_map(t_map *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
			{
				ft_free_str(game->map);
				ft_free_str(map);
				ft_error("Player can't reach all the coins or the exit.");
			}
			j++;
		}
		i++;
	}
}
