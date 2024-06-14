/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:08:44 by yakhadad          #+#    #+#             */
/*   Updated: 2023/12/08 20:08:47 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_putadrs_base(unsigned long nb, char *base, int *len)
{
	if (nb < 16)
		ft_putchar(base[nb], len);
	if (nb >= 16)
	{
		ft_putadrs_base(nb / 16, base, len);
		ft_putadrs_base(nb % 16, base, len);
	}
}

void	ft_putadrs(void *adrs, int *len)
{
	ft_putstr("0x", len);
	ft_putadrs_base((unsigned long)adrs, "0123456789abcdef", len);
}
