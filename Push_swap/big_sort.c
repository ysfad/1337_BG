/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 02:04:16 by yakhadad          #+#    #+#             */
/*   Updated: 2024/07/02 02:04:41 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_rotation(t_stack **a, t_stack **b, int c, long position)
{
	char	*r;
	char	*rr;
	long	mid;
	long	size;

	if (c == 'a')
	{
		size = ft_count_size(a);
		r = "ra";
		rr = "rra";
	}
	else
	{
		size = ft_count_size(b);
		r = "rb";
		rr = "rrb";
	}
	if (size % 2 != 0)
		mid = size / 2 + 1;
	else
		mid = size / 2;
	if (position <= mid)
		action(r, a, b);
	else
		action(rr, a, b);
}

void	ft_sort_5(t_stack **a, t_stack **b, long size, int *arr)
{
	long	i;
	long	position;
	int		pushes;

	i = 0;
	pushes = size - 4;
	while (pushes > 0)
	{
		position = find_position(a, arr[i], arr[i]);
		while ((*a)->num != arr[i])
			ft_rotation(a, b, 'a', position);
		action("pb", a, b);
		i++;
		pushes--;
	}
	if (ft_sorted_checker(a, 2) == 0)
		ft_sort_4(a, b);
	pushes = size - 4;
	while (pushes-- > 0)
		action("pa", a, b);
}

void	ft_range(long *start, long *end, long size, int cas)
{
	long	offset;

	if (size <= 250)
		offset = 10;
	else
		offset = 40;
	if (cas == 1)
	{
		*start = (size / 2 - 1) - offset;
		*end = (size / 2 - 1) + offset;
	}
	else
	{
		*start -= offset;
		*end += offset;
	}
	if (*start < 0)
		*start = 0;
	if (*end >= size)
		*end = size - 1;
}

void	ft_send_b(t_stack **a, t_stack **b, long size, int *arr)
{
	long	start;
	long	end;
	long	size2;
	long	position;
	long	sizeb;

	sizeb = 0;
	ft_range(&start, &end, size, 1);
	while (*a)
	{
		while (1)
		{
			position = find_position(a, arr[start], arr[end]);
			if (position == 0)
				break ;
			size2 = ft_count_size(a);
			while (!((*a)->num >= arr[start] && (*a)->num <= arr[end]))
				ft_rotation(a, b, 'a', position);
			action("pb", a, b);
			if ((*b)->num < arr[size / 2] && sizeb > 0)
				action("rb", a, b);
			sizeb = 1;
		}
		ft_range(&start, &end, size, 2);
	}
}

void	ft_big_sort(t_stack **a, t_stack **b, int *arr)
{
	long	size;
	long	size2;
	long	end;
	long	position;

	size = ft_count_size(a);
	end = size - 1;
	ft_send_b(a, b, size, arr);
	while (end >= 0)
	{
		position = find_position(b, arr[end], arr[end]);
		size2 = ft_count_size(b);
		while ((*b)->num != arr[end])
			ft_rotation(a, b, 'b', position);
		action("pa", a, b);
		end--;
	}
}
