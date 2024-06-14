/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:35:37 by yakhadad          #+#    #+#             */
/*   Updated: 2024/04/14 15:35:42 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_filler(char *result, char *buffer, char **str, size_t newline)
{
	char	*temp;

	if (!result && newline == 1)
		result = ft_strdup_v2(buffer, '\n');
	else if (!result && newline == 0)
		result = ft_strdup_v2(buffer, '\0');
	else if (result)
	{
		temp = ft_strjoin_v2(result, buffer);
		free(result);
		result = ft_strdup_v2(temp, '\0');
		free(temp);
	}
	if (newline == 1)
		*str = ft_strdup_v2(ft_strchr(buffer, '\n') + 1, '\0');
	if (ft_strchr(result, '\n') && *ft_strchr(result, '\n') + 1 != '\0')
	{
		temp = ft_strdup_v2(result, '\n');
		free(result);
		result = ft_strdup_v2(temp, '\n');
		free(temp);
	}
	free(buffer);
	return (result);
}

char	*ft_read(char *result, char **str, size_t fd)
{
	char	*buffer;
	ssize_t	numbytes;

	while (TRUE)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		numbytes = read(fd, buffer, BUFFER_SIZE);
		if (numbytes < 0)
		{
			free(buffer);
			free(result);
			return (NULL);
		}
		else if (numbytes == 0)
		{
			free(buffer);
			return (result);
		}
		buffer[numbytes] = '\0';
		if (ft_strchr(buffer, '\n'))
			return (ft_filler(result, buffer, &*str, 1));
		result = ft_filler(result, buffer, &*str, 0);
	}
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*str[10240];
	char		*temp;

	result = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (str[fd] && !ft_strchr(str[fd], '\n'))
	{
		result = ft_strdup_v2(str[fd], '\0');
		free(str[fd]);
		str[fd] = NULL;
	}
	else if (str[fd] && ft_strchr(str[fd], '\n'))
	{
		temp = ft_strdup_v2(str[fd], '\0');
		free(str[fd]);
		str[fd] = ft_strdup_v2(ft_strchr(temp, '\n') + 1, '\0');
		result = ft_strdup_v2(temp, '\n');
		free(temp);
		return (result);
	}
	return (ft_read(result, &str[fd], fd));
}
