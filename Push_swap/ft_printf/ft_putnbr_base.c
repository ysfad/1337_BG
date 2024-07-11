/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:09:15 by yakhadad          #+#    #+#             */
/*   Updated: 2023/12/08 20:09:17 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnbr_base(long nb, char *base, int *len)
{
	if (nb < 0)
	{
		ft_putchar('-', len);
		nb *= -1;
	}
	if (nb < 16)
		ft_putchar(base[nb], len);
	if (nb >= 16)
	{
		ft_putnbr_base(nb / 16, base, len);
		ft_putnbr_base(nb % 16, base, len);
	}
}
