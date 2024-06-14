/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:43:56 by yakhadad          #+#    #+#             */
/*   Updated: 2023/11/18 21:11:57 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	filler;

	tmp = s;
	filler = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		tmp[i] = filler;
		i++;
	}
	return (s);
}
