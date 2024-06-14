/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:01:17 by yakhadad          #+#    #+#             */
/*   Updated: 2023/11/30 18:05:20 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_strcount(const char *s, char c)
{
	int		i;
	size_t	numstr;

	i = 0;
	numstr = 0;
	while (s != NULL && *s != '\0')
	{
		if (*s != c && i == 0)
		{
			i = 1;
			numstr++;
		}
		else if (*s == c)
			i = 0;
		s++;
	}
	return (numstr);
}

static size_t	ft_charcount(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static int	ft_free(char **strings, size_t index)
{
	if (strings[index] == NULL)
	{
		while (index--)
			free(strings[index]);
		free(strings);
		return (1);
	}
	return (2);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	numstr;
	char	**strings;

	numstr = ft_strcount(s, c);
	strings = (char **)malloc((numstr + 1) * sizeof(char *));
	if (strings == NULL)
		return (NULL);
	i = 0;
	while (s && *s && i < numstr)
	{
		while (*s == c)
			s++;
		count = ft_charcount(s, c);
		strings[i] = (char *)malloc(count + 1);
		if (ft_free(strings, i) == 1)
			return (NULL);
		ft_strlcpy(strings[i], s, count + 1);
		s = s + count;
		i++;
	}
	strings[numstr] = NULL;
	return (strings);
}
