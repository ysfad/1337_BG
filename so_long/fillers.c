/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:20:19 by yakhadad          #+#    #+#             */
/*   Updated: 2024/07/13 14:20:33 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char	*ft_fill_map_2(t_map *game, char *line, char *tmp)
{
	char	*tmp2;

	while (1)
	{
		free(line);
		line = get_next_line(game->fd);
		game->height++;
		if (line == NULL)
			break ;
		tmp2 = ft_strjoin(tmp, line);
		free(tmp);
		tmp = ft_strdup(tmp2);
		free(tmp2);
		if (tmp == NULL)
		{
			free(line);
			free(tmp);
			ft_error("problem while allocating the map lines.");
		}
	}
	return (tmp);
}

char	*ft_fill_map(t_map *game, char *file)
{
	char	*line;
	char	*tmp;

	game->fd = open(file, O_RDONLY);
	if (game->fd < 0)
	{
		close(game->fd);
		ft_error("file doesn't exist");
	}
	line = get_next_line(game->fd);
	if (line == NULL || *line == '\0')
	{
		free(line);
		close(game->fd);
		ft_error("empty file.");
	}
	tmp = ft_strdup(line);
	tmp = ft_fill_map_2(game, line, tmp);
	return (tmp);
}

void	ft_split_map(t_map *game, char *tmp)
{
	int	i;

	game->map = ft_split(tmp, '\n');
	free(tmp);
	if (game->map == NULL)
		ft_error("problem while allocating the map lines.");
	game->width = ft_strlen(*game->map);
	i = 1;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != game->width)
		{
			ft_free_str(game->map);
			ft_error("all lines must be equals");
		}
		i++;
	}
}

void	ft_struct_fill(t_map *game)
{
	game->fd = 0;
	game->width = 0;
	game->height = 0;
	game->coins = 0;
	game->x = 0;
	game->y = 0;
	game->steps = 0;
	game->character = NULL;
	game->door = NULL;
	game->o_door = NULL;
	game->land = NULL;
	game->wall = NULL;
	game->ring = NULL;
	game->map = NULL;
	game->bonus = NULL;
}
