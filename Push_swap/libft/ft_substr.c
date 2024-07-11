/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:31:02 by yakhadad          #+#    #+#             */
/*   Updated: 2023/11/22 22:18:09 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			slen;
	size_t			length;
	char			*src;
	char			*dest;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len + start > slen)
		length = slen - start + 1;
	else
		length = len + 1;
	src = (char *)s + start;
	dest = malloc(length * sizeof(char));
	if (dest == NULL)
		return (NULL);
	if (s[0] != '\0')
	{
		ft_strlcpy(dest, src, length);
		return (dest);
	}
	return ((char *)s);
}
