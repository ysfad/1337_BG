/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:28:25 by yakhadad          #+#    #+#             */
/*   Updated: 2024/05/31 11:29:32 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_node(t_stack **node)
{
	t_stack *tmp;

	tmp = *node;
	while(tmp->next)
	{
		while(tmp->next->next)
			tmp = tmp->next;
		free(tmp->next);
		tmp->next = NULL;
		tmp = *node;
	}
	free(tmp);
}

void	ft_error(t_stack **a)
{
	if (*a)
		free_node(a);
	ft_printf("Error\n");
	exit(1);
}

void	ft_check_node(t_stack **a, t_stack **b)
{
	if (*a)
		free_node(a);
	if (*b)
		free_node(b);
	*a = NULL;
	ft_error(a);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
	free(str);
}

void	ft_str_error(t_stack **a, char **str)
{
	free_str(str);
	ft_error(a);
}
