/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:13:32 by yakhadad          #+#    #+#             */
/*   Updated: 2024/07/13 14:26:29 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_check_ber(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len == 4)
		ft_error("file must be (file_name.ber).");
	str = str + len - 4;
	if (str[0] != '.' || str[1] != 'b' || str[2] != 'e' || str[3] != 'r')
		ft_error("file must be (file_name.ber).");
}

void	ft_check_lines(char *tmp)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (*tmp == '\n')
		x = 1;
	while (tmp[i] && x == 0)
	{
		if (tmp[i] == '\n' && tmp[i + 1] == '\n')
			x = 1;
		i++;
	}
	if (x == 1)
	{
		free(tmp);
		ft_error("extra new line somewhere in the file.");
	}
}

void	ft_check_walls(t_map *game)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	while (i < game->height && x == 0)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[0][j] != '1' || game->map[i][game->width - 1] != '1'
				|| game->map[game->height - 1][j] != '1'
				|| game->map[i][0] != '1')
				x = 1;
			j++;
		}
		i++;
	}
	if (x == 1)
	{
		ft_free_str(game->map);
		ft_error("all walls must equal 1.");
	}
}

void	ft_check_p_e_c(t_map *game, char e, char *str)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (count == 0 && game->map[i][j] == e)
				count++;
			j++;
			if (count != 0 && game->map[i][j] == e)
				count++;
		}
		i++;
	}
	ft_element_error(game, count, e, str);
	if (e == 'C')
		game->coins = count;
}

void	ft_check_elements(t_map *game)
{
	ft_check_p_e_c(game, 'P', "player");
	ft_check_p_e_c(game, 'E', "exit");
	ft_check_p_e_c(game, 'C', NULL);
	ft_check_land(game);
}
