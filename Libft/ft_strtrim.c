/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:42:23 by yakhadad          #+#    #+#             */
/*   Updated: 2023/12/04 17:55:33 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*dest;

	i = 0;
	if (!s1 || !set)
		return ((char *)s1);
	len = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (i == len)
	{
		dest = (char *)malloc(1);
		if (dest == NULL)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	while (s1[len - 1] && ft_strchr(set, s1[len - 1]))
		len--;
	dest = (char *)malloc(len - i + 1);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s1 + i, len - i + 1);
	return (dest);
}
