/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:46:47 by yakhadad          #+#    #+#             */
/*   Updated: 2023/11/21 15:47:44 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	total;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	total = count * size;
	p = malloc(total);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, total);
	return (p);
}
