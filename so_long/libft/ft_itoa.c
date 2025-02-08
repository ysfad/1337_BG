/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:32:55 by yakhadad          #+#    #+#             */
/*   Updated: 2023/11/25 15:33:04 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_filler(unsigned int nb, int n, int len)
{
	char	*result;

	result = (char *)malloc(len);
	if (result == NULL)
		return (NULL);
	result[--len] = '\0';
	while (len > 0)
	{
		result[--len] = (nb % 10) + 48;
		nb /= 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}

char	*ft_itoa(int n)
{
	int				len;
	unsigned int	nb;
	unsigned int	tmp;

	if (n < 0)
		nb = n * -1;
	else
		nb = n;
	len = 0;
	tmp = nb;
	while (tmp > 0)
	{
		tmp /= 10;
		len++;
	}
	if (n <= 0)
		len += 2;
	else
		len++;
	return (ft_filler(nb, n, len));
}
