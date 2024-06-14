/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:39:21 by yakhadad          #+#    #+#             */
/*   Updated: 2023/11/20 21:21:59 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*t;
	unsigned char		ch;

	i = 0;
	ch = c;
	t = s;
	while (i < n)
	{
		if (*t == ch)
			return ((void *)t);
		i++;
		t++;
	}
	return (0);
}
