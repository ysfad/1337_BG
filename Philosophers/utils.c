/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:17:26 by yakhadad          #+#    #+#             */
/*   Updated: 2024/11/25 18:17:28 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != 0 || sign < 0 || nb > 2147483647)
		ft_error("Input must be positive numbers less than 2147483648", NULL);
	return (nb * sign);
}

void	ft_error(char *str, t_args *acts)
{
	if (acts)
	{
		if (acts->philos)
			free(acts->philos);
		if (acts->forks)
			free(acts->forks);
	}
	printf("%s\n", str);
	exit(1);
}

long	ft_get_time(t_args *acts)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		ft_error("gettimeofday failure", acts);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ft_check_dead(t_philosophers *philo)
{
	pthread_mutex_lock(&philo->acts->dead_lock);
	if (philo->acts->philo_died == 1)
	{
		pthread_mutex_unlock(&philo->acts->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->acts->dead_lock);
	return (0);
}

int	ft_print_message(char *str, t_philosophers *philo, int cas)
{
	long	time;
	int		tmp;

	pthread_mutex_lock(&philo->acts->msg_lock);
	time = ft_get_time(philo->acts) - philo->acts->start_time;
	tmp = cas;
	if (tmp == 1)
		philo->last_meal_time = time;
	if (philo->acts->philo_died == 1)
	{
		pthread_mutex_unlock(&philo->acts->msg_lock);
		return (1);
	}
	printf("%ld %d %s\n", time, philo->id, str);
	if (tmp == 2)
		philo->acts->philo_died = 1;
	pthread_mutex_unlock(&philo->acts->msg_lock);
	return (0);
}
