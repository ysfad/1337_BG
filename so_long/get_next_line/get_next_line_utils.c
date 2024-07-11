/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 02:33:16 by yakhadad          #+#    #+#             */
/*   Updated: 2024/03/29 02:33:24 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_v2(char *s, int c)
{
	unsigned char	ch;

	ch = c;
	while (s[0])
	{
		if (s[0] == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (0);
}

size_t	ft_strlen_v2(char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != c)
		i++;
	return (i);
}

char	*ft_strdup_v2(char *s1, char c)
{
	size_t	len;
	size_t	i;
	int		x;
	char	*s2;

	if (*s1 == '\0')
		return (NULL);
	x = 0;
	if (c == '\0')
		x = 1;
	else if (c == '\n')
		x = 2;
	len = ft_strlen_v2(s1, c) + x;
	s2 = (char *)malloc(sizeof(char) * len);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i < len - 1 && s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin_v2(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;
	char	*s;

	len1 = ft_strlen_v2(s1, '\0');
	len2 = ft_strlen_v2(s2, '\0');
	if (!s1 || !s2)
		return (NULL);
	s = (char *)malloc(len1 + len2 + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (i < len1 && s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2 && s2[j])
		s[i++] = s2[j++];
	s[i] = '\0';
	return (s);
}
