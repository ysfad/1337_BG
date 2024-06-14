/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:46:43 by yakhadad          #+#    #+#             */
/*   Updated: 2024/05/31 09:46:51 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_fill_index(t_stack **a, int *tab, long size)
{
	long	i;
	t_stack *tmp;

	tmp = *a;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] == tmp->num)
			{
				tmp->index = i;
				break;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	ft_sort_array(t_stack **a, int *tab, long size)
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
	ft_fill_index(a, tab, size);
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
	ft_sort_array(a, arr, size);
	return (arr);
}

long	ft_find_min(t_stack **a, long index)
{
	long	position;
	t_stack	*tmp;

	tmp = *a;
	position = 1;
	while (tmp)
	{
		if (tmp->index == index)
			break;
		tmp = tmp->next;
		position++;
	}
	return (position);
}

void	ft_sort_5(t_stack **a, t_stack **b, long size)
{
	long	index;
	long	position;
	int		pushes;

	index = 0;
	pushes = size - 4;
	while(pushes > 0)
	{
		position = ft_find_min(a, index);
		while ((*a)->index != index)
		{
			if (position <= (size / 2))
				action("ra", a, b);
			else
				action("rra", a, b);
		}
		action("pb", a, b);
		index++;
		pushes--;
	}
	if (ft_sorted_checker(a, 2) == 0)
		ft_sort_4(a, b);
	pushes = size - 4;
	while (pushes-- > 0)
		action("pa", a, b);
}

void	ft_big_sort(t_stack **a, t_stack **b, long size, int *arr)
{
	long	mid;
	long	div;
	long	offset;
	long	start;
	long	end;

	mid = size / 2 - 1;
	div = size / 2;
	offset = size / div;
	start = mid - offset;
	end = mid + offset;

}

void	ft_sort_stack(t_stack **a, t_stack **b, long size)
{
	int	*arr;

	arr = ft_array(a, size);
	if (size == 2)
		action("sa", a, b);
	else if (size == 3)
		ft_sort_3(a);
	else if (size == 4)
		ft_sort_4(a, b);
	else if (size == 5 || size == 6)
		ft_sort_5(a, b, size);
	else 
		ft_big_sort(a, b, size, arr);
	free(arr);
}

int	main(int ac, char **av)
{
	long	size;
	t_stack	*a;
	t_stack	*b;
	t_stack	*tmp;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	av++;
	ft_stack_checker(&b, av);
	ft_dup_checker(&b);
	size = ft_count_size(&a, &b);
	ft_sorted_checker(&a, 1);
	ft_sort_stack(&a, &b, size);
	tmp = a;
    while (tmp)
	{
		ft_printf("%i ", tmp->num);
		tmp = tmp->next;
	}
    ft_printf("\n");
	if (a)
		free_node(&a);
	if (b)
		free_node(&b);
}
