/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:57:15 by yakhadad          #+#    #+#             */
/*   Updated: 2023/11/25 20:58:01 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (fd >= 0)
	{
		i = 0;
		while (s && s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

/*#include <fcntl.h>
int main(void){
	int	fd = open("text.txt", O_CREAT | O_WRONLY, 0543);
	ft_putstr_fd("yous", fd);
	close(fd);
}*/