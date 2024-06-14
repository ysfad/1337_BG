/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:34:35 by yakhadad          #+#    #+#             */
/*   Updated: 2023/11/21 14:43:29 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *s)
{
	int				i;
	int				sign;
	unsigned int	nb;

	i = 0;
	nb = 0;
	sign = 1;
	while (s[i] == '\t' || s[i] == '\r' || s[i] == '\f' || s[i] == '\v'
		|| s[i] == '\n' || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] > 47 && s[i] < 58)
	{
		nb = nb * 10 + (s[i] - 48);
		i++;
	}
	return (nb * sign);
}
