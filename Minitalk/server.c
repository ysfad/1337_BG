/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:37:08 by yakhadad          #+#    #+#             */
/*   Updated: 2024/05/10 22:37:09 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

void	ft_write(int *c, int *counter)
{
	write(1, c, 1);
	*counter = 0;
	*c = 0;
}

void	ft_handler(int sig, siginfo_t *info, void *notused)
{
	static int		counter;
	static int		c;
	static pid_t	pid;

	(void)notused;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		counter = 0;
		c = 0;
	}
	if (sig == SIGUSR1)
		c = c | 1;
	else
		c = c | 0;
	if (counter < 7)
	{
		c = c << 1;
		counter++;
	}
	else if (counter == 7)
		ft_write(&c, &counter);
}

int	main(void)
{
	struct sigaction	action;
	pid_t				pid;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = ft_handler;
	pid = getpid();
	ft_printf("\n\n<=====================MINITALK=====================>\n\n");
	ft_printf("USERNAME: Yakhadad.\n");
	ft_printf("SERVER PID: %i.\n\n", pid);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		;
}
