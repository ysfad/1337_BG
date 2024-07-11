/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:26:49 by yakhadad          #+#    #+#             */
/*   Updated: 2023/12/06 19:26:54 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_check(char c, va_list args, int *len)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), len);
	if (c == 's')
		ft_putstr(va_arg(args, char *), len);
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), len);
	if (c == 'u')
		ft_unsigned(va_arg(args, unsigned int), len);
	if (c == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", len);
	if (c == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", len);
	if (c == 'p')
		ft_putadrs(va_arg(args, void *), len);
	if (c == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
			ft_check(str[++i], args, &len);
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
