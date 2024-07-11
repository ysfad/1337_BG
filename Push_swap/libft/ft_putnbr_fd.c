/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:10:23 by yakhadad          #+#    #+#             */
/*   Updated: 2023/11/25 21:11:05 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (fd >= 0)
	{
		if (n < 0)
		{
			nb = n * -1;
			write(fd, "-", 1);
		}
		else
			nb = n;
		if (nb < 10)
			ft_putchar_fd(nb + 48, fd);
		else
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putchar_fd((nb % 10) + 48, fd);
		}
	}
}
