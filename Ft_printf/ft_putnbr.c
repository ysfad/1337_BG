/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:09:09 by yakhadad          #+#    #+#             */
/*   Updated: 2023/12/08 20:09:10 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnbr(int n, int *len)
{
	unsigned int	nb;

	if (n < 0)
	{
		nb = n * -1;
		ft_putchar('-', len);
	}
	else
		nb = n;
	if (nb < 10)
		ft_putchar(nb + 48, len);
	else
	{
		ft_putnbr(nb / 10, len);
		ft_putchar((nb % 10) + 48, len);
	}
}
