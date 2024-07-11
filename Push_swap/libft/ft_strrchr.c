/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:20:28 by yakhadad          #+#    #+#             */
/*   Updated: 2023/11/15 21:22:42 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	const char		*tmp;
	unsigned char	ch;

	i = 0;
	ch = c;
	tmp = s;
	while (s[0])
	{
		if (s[0] == ch)
		{
			tmp = s;
			i++;
		}
		s++;
	}
	if (i != 0)
		return ((char *)tmp);
	if (ch == '\0')
		return ((char *)s);
	return (0);
}
