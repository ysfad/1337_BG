/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:46:43 by yakhadad          #+#    #+#             */
/*   Updated: 2024/07/02 22:20:44 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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
		ft_sort_5(a, b, size, arr);
	else
		ft_big_sort(a, b, arr);
	free(arr);
}

int	main(int ac, char **av)
{
	long	size;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	av++;
	ft_stack_checker(&b, av);
	ft_dup_checker(&b);
	size = ft_count_size(&b);
	ft_fill_a(&a, &b, size);
	ft_sorted_checker(&a, 1);
	ft_sort_stack(&a, &b, size);
	if (a)
		free_node(&a);
	if (b)
		free_node(&b);
}
