/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:36:37 by yakhadad          #+#    #+#             */
/*   Updated: 2024/05/31 10:36:42 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	action_2(char *s, t_stack **a, t_stack **b)
{
	if (ft_memcmp(s, "rra", 4) == 0)
		ft_reverse_rotate(a);
	else if (ft_memcmp(s, "rrb", 4) == 0)
		ft_reverse_rotate(b);
	else if (ft_memcmp(s, "rrr", 4) == 0)
	{
		ft_reverse_rotate(a);
		ft_reverse_rotate(b);
	}
	else if (ft_memcmp(s, "pa", 3) == 0)
		ft_push(b, a);
	else if (ft_memcmp(s, "pb", 3) == 0)
		ft_push(a, b);
}

void	action(char *s, t_stack **a, t_stack **b)
{
	if (ft_memcmp(s, "sa", 3) == 0)
		ft_swap(*a);
	else if (ft_memcmp(s, "sb", 3) == 0)
		ft_swap(*b);
	else if (ft_memcmp(s, "ss", 3) == 0)
	{
		ft_swap(*a);
		ft_swap(*b);
	}
	else if (ft_memcmp(s, "ra", 3) == 0)
		ft_rotate(a);
	else if (ft_memcmp(s, "rb", 3) == 0)
		ft_rotate(b);
	else if (ft_memcmp(s, "rr", 3) == 0)
	{
		ft_rotate(a);
		ft_rotate(b);
	}
	else
		action_2(s, a, b);
	ft_printf("%s\n", s);
}
