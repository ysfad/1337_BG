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

char	**ft_copy_map(t_map *game)
{
	int		i;
	char	**copy_map;

	i = 0;
	copy_map = (char **)malloc((game->hight + 1) * sizeof(char *));
	while (game->map[i])
	{
		copy_map[i] = ft_strdup(game->map[i]);
		i++;
	}
	copy_map[i] = NULL;
	return (copy_map);
}

void    ft_location(t_map *game, char **map)
{
    int i;
    int j;

    i = 1;
    while(i < game->hight - 1)
    {
        j = 1;
        while(j < game->width - 1)
        {
            if (map[i][j] == 'E')
			{
				game->exit[0] = j;
				game->exit[1] = i;
			}
			if (map[i][j] == 'P')
			{
				game->player[0] = j;
				game->player[1] = i;
			}
			j++;
		}
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

void	ft_flood_fill(char **map, int *i, int *j)
{
	while()
	{
		
	}
}

void	ft_reach_exit(t_map *game, char **map)
{
	int	i;
	int	j;

	i = game->exit[1];
	j = game->exit[0];
	while(map[i - 1][j] != 'P' && map[i + 1][j] != 'P'
		&& map[i][j - 1] != 'P' && map[i][j + 1] != 'P')
	{
		if (map[i - 1][j] != '1' && map[i + 1][j] != '1'
		&& map[i][j - 1] != '1' && map[i][j + 1] != '1')
			break;
		ft_flood_fill(map, &i, &j);
	}
	if (map[i - 1][j] != 'P' && map[i + 1][j] != 'P'
		&& map[i][j - 1] != 'P' && map[i][j + 1] != 'P')
	{
		ft_free_str(game->map);
		ft_free_str(map);
		ft_error("Error\nplayer can't reach the exit.");
	}
}

void	ft_check_road(t_map *game)
{
	char	**map_copy;

	map_copy = ft_copy_map(game);
	ft_location(game, map_copy);
	ft_reach_exit(game, map_copy);
}

void	ft_map(t_map *game, char *file)
{
	char	*lines;

	lines = ft_fill_map(game, file);
	ft_check_lines(lines);
	ft_split_map(game, lines);
	ft_check_walls(game);
	ft_check_elements(game);
	ft_check_road(game);
}

void	ft_struct_fill(t_map *game)
{
	int	i;

	i = 0;
	game->fd = 0;
	game->width = 0;
	game->hight = 0;
	game->coins = 0;
	while(i < 2)
	{
		game->exit[i] = 0;
		game->player[i] = 0;
		i++;
	}
	game->map = NULL;
}

int	main(int ac, char **av)
{
	t_map game;

	if (ac != 2)
		return (0);
	ft_check_ber(av[1]);
	ft_struct_fill(&game);
	ft_map(&game, av[1]);
}
