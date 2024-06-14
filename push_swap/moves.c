/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:50:46 by yakhadad          #+#    #+#             */
/*   Updated: 2024/05/31 09:50:50 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_swap(t_stack *x)
{
	int	tmp;

	if (x && x->next)
	{
		tmp = x->num;
		x->num = x->next->num;
		x->next->num = tmp;
	}
}

void	ft_rotate(t_stack **x)
{
	t_stack	*tmp;

	if (*x && (*x)->next)
	{
		tmp = *x;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *x;
		*x = (*x)->next;
		tmp->next->next = NULL;
	}
}

void	ft_reverse_rotate(t_stack **x)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*x && (*x)->next)
	{
		tmp = *x;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp2 = tmp->next;
		tmp->next = NULL;
		tmp2->next = *x;
		*x = tmp2;
	}
}

void	ft_push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*src)
	{
		tmp = *src;
		tmp2 = *dst;
		*src = (*src)->next;
		*dst = tmp;
		tmp->next = tmp2;
	}
}
