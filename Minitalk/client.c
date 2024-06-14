/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:36:33 by yakhadad          #+#    #+#             */
/*   Updated: 2024/05/10 22:36:38 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

int	ft_atoi(const char *s)
{
	int				i;
	unsigned int	nb;

	i = 0;
	nb = 0;
	while (s[i] > 47 && s[i] < 58)
	{
		nb = nb * 10 + (s[i] - 48);
		i++;
	}
	if (!(s[i] >= 48 && s[i] <= 57) && s[i] != 0)
		return (-1);
	return (nb);
}

void	ft_message(pid_t pid, char *str)
{
	unsigned long	i;
	int				j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			if (((str[i] >> j) & 1) == 1)
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(1);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(1);
			}
			j--;
			usleep(300);
		}
		i++;
	}
	exit(0);
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac == 3)
		pid = ft_atoi(av[1]);
	else
	{
		ft_printf("INSERT TWO ARGUMENTS: \"PID\" \"STRING\"\n");
		return (0);
	}
	if (pid <= 0)
	{
		ft_printf("Invalide PID\n");
		return (0);
	}
	ft_message(pid, av[2]);
}
