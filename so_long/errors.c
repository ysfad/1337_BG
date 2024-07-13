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

void    ft_element_error(t_map *game, int c, char e, char *str)
{
    if (c == 0 && e == 'C')
    {
        ft_free_str(game->map);
        ft_error("Error\nthere must be at least 1 coin (C).");
    }
    if (c != 1 && e != 'C')
    {
        ft_free_str(game->map);
        ft_printf("Error\nthere must be 1 %s (%c).\n", str, e);
        exit(1);
    }
}
