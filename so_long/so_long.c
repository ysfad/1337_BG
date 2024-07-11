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

void    ft_error(void)
{
    ft_printf("Error\n");
    exit(1);
}

void    ft_check_ber(char *str)
{
    int len;

    len = ft_strlen(str);
    if (len == 4)
        ft_error();
    str = str + len - 4;
    if (str[0] != '.' && str[1] != 'b' && str[1] != 'B'
        && str[2] != 'e' && str[2] != 'E'
        && str[3] != 'r' && str[3] != 'R')
        ft_error();
}

char    *ft_arr_fill(char *line)
{
    int     len;
    char    *tmp;

    len = ft_strlen(line);
    tmp = malloc(sizeof(char) * (len + 1));
    if (tmp == NULL)
    {
        free (tmp);
        return (NULL);
    }
    ft_strlcpy(tmp, line, len);
    return (tmp);
}

void    ft_map(t_map *map, char *file)
{
    int     i;
    char    *line;

    i = 0;
    map->fd = open(file, O_RDONLY);
    while(1)
    {
        line = get_next_line(map->fd);
        if (line == NULL)
            break;
        map->arr[i] = ft_arr_fill(line);
        if (map->arr[i] == NULL)
            ft_error();
        map->hight++;
        if (map->width == 0)
            map->width = ft_strlen(line);
        if (map->width != ft_strlen(line))
            ft_error();
        i++;
    }
}

void    ft_struct_fill(t_map *map)
{
    map->fd = 0;
    map->width = 0;
    map->hight = 0;
    map->arr = NULL;
}

int main(int ac, char **av)
{
    t_map map;

    if (ac != 2)
        return(0);
    ft_check_ber(av[1]);
    ft_struct_fill(&map);
    ft_map(&map, av[1]);
}