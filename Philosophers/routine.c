/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:17:20 by yakhadad          #+#    #+#             */
/*   Updated: 2024/11/25 18:17:22 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_one_philo(t_philosophers *philo)
{
	pthread_mutex_lock(philo->right_hand);
	ft_print_message("has taken a fork", philo, 0);
	usleep(philo->acts->time_death);
	pthread_mutex_unlock(philo->right_hand);
	return (NULL);
}

int	ft_split_philos(t_philosophers *philo)
{
	pthread_mutex_lock(&philo->acts->dead_lock);
	if (philo->acts->philo_died == 1 || philo->eat_count == 0)
	{
		pthread_mutex_unlock(&philo->acts->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->acts->dead_lock);
	if (philo->id == 1 && philo->acts->num_philo != 2)
	{
		if (ft_one(philo) == 1)
			return (1);
	}
	else if ((philo->id) % 2 == 0)
	{
		if (ft_even(philo) == 1)
			return (1);
	}
	else if (ft_odd(philo) == 1)
		return (1);
	return (0);
}

void	*ft_routine(void *my_struct)
{
	t_philosophers	*philo;

	philo = (t_philosophers *)my_struct;
	if (philo->acts->num_philo == 1)
		return (ft_one_philo(philo));
	while (1)
	{
		if (ft_split_philos(philo) == 1)
			break ;
	}
	if (philo->eat_count == 0)
	{
		pthread_mutex_lock(&philo->acts->full_lock);
		philo->acts->full_philos++;
		pthread_mutex_unlock(&philo->acts->full_lock);
	}
	return (NULL);
}

int	ft_dead_philo(t_args *acts, int i)
{
	long	time;

	pthread_mutex_lock(&acts->msg_lock);
	time = (ft_get_time(acts) - acts->start_time)
		- acts->philos[i].last_meal_time;
	pthread_mutex_unlock(&acts->msg_lock);
	if (time > acts->time_death)
	{
		if (acts->eat_limit == 1)
		{
			if (acts->philos[i].eat_count == 0)
				return (0);
		}
		pthread_mutex_lock(&acts->dead_lock);
		ft_print_message("died", &acts->philos[i], 2);
		pthread_mutex_unlock(&acts->dead_lock);
		return (1);
	}
	return (0);
}

void	*ft_monitor(void *my_struct)
{
	int		i;
	t_args	*acts;

	i = 0;
	acts = (t_args *)my_struct;
	while (1)
	{
		pthread_mutex_lock(&acts->full_lock);
		if (acts->full_philos == acts->num_philo)
		{
			pthread_mutex_unlock(&acts->full_lock);
			break ;
		}
		if (i == acts->num_philo)
			i = 0;
		pthread_mutex_unlock(&acts->full_lock);
		if (ft_dead_philo(acts, i) == 1)
			break ;
		i++;
	}
	return (NULL);
}
