/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 00:18:12 by yakhadad          #+#    #+#             */
/*   Updated: 2024/07/02 22:00:29 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_sort_3(t_stack **a)
{
	int		i;
	int		j;
	int		k;
	t_stack	*tmp;

	tmp = *a;
	i = tmp->num;
	j = tmp->next->num;
	k = tmp->next->next->num;
	if (j > i && j > k)
	{
		action("rra", a, NULL);
		if (k > i)
			action("sa", a, NULL);
	}
	else if (j < i && j > k)
	{
		action("ra", a, NULL);
		action("sa", a, NULL);
	}
	else if (j < i && j < k && k > i)
		action("sa", a, NULL);
	else
		action("ra", a, NULL);
}

int	ft_which_case(t_stack **a)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = (*a)->num;
	j = (*a)->next->num;
	k = (*a)->next->next->num;
	l = (*a)->next->next->next->num;
	if (i < j && i < k && i < l)
		return (1);
	else if (j < i && j < k && j < l)
		return (2);
	else if (k < i && k < j && k < l)
		return (3);
	else
		return (4);
}

void	ft_sort_4(t_stack **a, t_stack **b)
{
	int	cas;

	cas = 0;
	cas = ft_which_case(a);
	if (cas == 1)
	{
		action("pb", a, b);
		ft_sort_3(a);
	}
	else if (cas == 2)
		action("sa", a, b);
	else if (cas == 3)
	{
		action("ra", a, b);
		action("ra", a, b);
	}
	else if (cas == 4)
		action("rra", a, b);
	if (ft_sorted_checker(a, 2) == 0)
	{
		action("pb", a, b);
		ft_sort_3(a);
	}
	if (*b)
		action("pa", a, b);
}
