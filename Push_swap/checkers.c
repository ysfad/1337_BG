/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 00:17:54 by yakhadad          #+#    #+#             */
/*   Updated: 2024/07/02 22:14:35 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_atoi_v2(char *s, t_stack **a, t_stack **tmp)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	nb = 0;
	sign = 1;
	while (s[i] == '\t' || s[i] == '\r' || s[i] == '\f' || s[i] == '\v'
		|| s[i] == '\n' || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[0] == '-')
			sign = -1;
		i++;
	}
	while (s[i] > 47 && s[i] < 58)
	{
		nb = nb * 10 + (s[i] - 48);
		i++;
	}
	if (s[i] != 0 || i == 0 || (s[i - 1] == '-' || s[i - 1] == '+')
		|| nb * sign < -2147483648 || nb * sign > 2147483647)
		ft_check_node(a, tmp);
	return (nb * sign);
}

void	ft_stack_filler(t_stack **a, char *s)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (tmp == NULL)
		ft_check_node(a, &tmp);
	tmp->num = ft_atoi_v2(s, a, &tmp);
	tmp->next = *a;
	*a = tmp;
	tmp = NULL;
}

void	ft_stack_checker(t_stack **a, char **s)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	while (s[i])
	{
		x = 0;
		j = 0;
		while (s[i] && s[i][j] && x == 0)
		{
			if (s[i][j] != ' ' && !(s[i][j] >= '0' && s[i][j] <= '9')
				&& s[i][j] != '-' && s[i][j] != '+')
				ft_error(a);
			if (s[i][j] == ' ')
			{
				ft_split_2(a, s[i]);
				x = 1;
			}
			j++;
		}
		if (x == 0)
			ft_stack_filler(a, s[i]);
		i++;
	}
}

void	ft_str_checker(char *s, t_stack **a, char **str)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	nb = 0;
	sign = 1;
	while (s[i] == '\t' || s[i] == '\r' || s[i] == '\f' || s[i] == '\v'
		|| s[i] == '\n' || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[0] == '-')
			sign = -1;
		i++;
	}
	while (s[i] > 47 && s[i] < 58)
	{
		nb = nb * 10 + (s[i] - 48);
		i++;
	}
	if (s[i] != 0 || i == 0 || (s[i - 1] == '-' || s[i - 1] == '+')
		|| nb * sign < -2147483648 || nb * sign > 2147483647)
		ft_str_error(a, str);
}

void	ft_split_2(t_stack **a, char *s)
{
	int		i;
	char	**str;

	str = ft_split(s, ' ');
	if (*str == NULL)
		ft_str_error(a, str);
	i = 0;
	while (str[i])
	{
		ft_str_checker(str[i], a, str);
		i++;
	}
	ft_stack_checker(a, str);
	free_str(str);
}
