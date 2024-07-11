/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 02:02:27 by yakhadad          #+#    #+#             */
/*   Updated: 2024/07/02 02:02:48 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_sort_array(int *tab, long size)
{
	long	i;
	long	j;
	int		tmp;

	j = size;
	while (j-- > 0)
	{
		i = 0;
		while (i < j)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
	}
}

int	*ft_array(t_stack **a, long size)
{
	long	i;
	int		*arr;
	t_stack	*tmp;

	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
	{
		free(arr);
		ft_error(a);
	}
	tmp = *a;
	i = 0;
	while (tmp)
	{
		arr[i] = tmp->num;
		tmp = tmp->next;
		i++;
	}
	ft_sort_array(arr, size);
	return (arr);
}

long	find_position(t_stack **a, int start, int end)
{
	long	position;
	t_stack	*tmp;

	tmp = *a;
	position = 1;
	while (tmp)
	{
		if (tmp->num >= start && tmp->num <= end)
			break ;
		tmp = tmp->next;
		position++;
	}
	if (tmp == NULL)
		return (0);
	return (position);
}
