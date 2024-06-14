/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:12:21 by yakhadad          #+#    #+#             */
/*   Updated: 2023/11/20 11:26:26 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tdst;
	unsigned char	*tsrc;

	i = 0;
	tdst = (unsigned char *)dest;
	tsrc = (unsigned char *)src;
	if (tdst == tsrc)
		return (tsrc);
	if (!tdst && !tsrc)
		return (0);
	while (i < len)
	{
		tdst[i] = tsrc[i];
		i++;
	}
	return (dest);
}
