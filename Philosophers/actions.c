/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:14:56 by yakhadad          #+#    #+#             */
/*   Updated: 2024/11/25 18:14:58 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_drop_one(t_philosophers *philo, pthread_mutex_t *lock)
{
	pthread_mutex_lock(&philo->acts->dead_lock);
	if (philo->acts->philo_died == 1)
	{
		pthread_mutex_unlock(lock);
		pthread_mutex_unlock(&philo->acts->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->acts->dead_lock);
	return (0);
}

int	ft_drop_two(t_philosophers *philo)
{
	pthread_mutex_lock(&philo->acts->dead_lock);
	if (philo->acts->philo_died == 1)
	{
		pthread_mutex_unlock(philo->left_hand);
		pthread_mutex_unlock(philo->right_hand);
		pthread_mutex_unlock(&philo->acts->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->acts->dead_lock);
	return (0);
}

int	ft_odd(t_philosophers *philo)
{
	if (ft_check_dead(philo) == 1)
		return (1);
	pthread_mutex_lock(philo->left_hand);
	if (ft_drop_one(philo, philo->left_hand) == 1)
		return (1);
	ft_print_message("has taken a fork", philo, 0);
	pthread_mutex_lock(philo->right_hand);
	if (ft_drop_two(philo) == 1)
		return (1);
	ft_print_message("has taken a fork", philo, 0);
	if (ft_print_message("is eating", philo, 1) == 1)
		return (ft_drop_two(philo));
	usleep(philo->acts->time_eat * 1000 + philo->acts->sleep_case);
	if (philo->acts->eat_limit == 1)
		philo->eat_count--;
	pthread_mutex_unlock(philo->left_hand);
	pthread_mutex_unlock(philo->right_hand);
	if (ft_check_dead(philo) == 1)
		return (1);
	if (ft_print_message("is sleeping", philo, 0) == 0)
		usleep(philo->acts->time_sleep * 1000);
	ft_print_message("is thinking", philo, 0);
	usleep(200);
	return (0);
}

int	ft_one(t_philosophers *philo)
{
	if (ft_check_dead(philo) == 1)
		return (1);
	pthread_mutex_lock(philo->right_hand);
	if (ft_drop_one(philo, philo->right_hand) == 1)
		return (1);
	ft_print_message("has taken a fork", philo, 0);
	pthread_mutex_lock(philo->left_hand);
	if (ft_drop_two(philo) == 1)
		return (1);
	ft_print_message("has taken a fork", philo, 0);
	if (ft_print_message("is eating", philo, 1) == 1)
		return (ft_drop_two(philo));
	usleep(philo->acts->time_eat * 1000 + philo->acts->sleep_case);
	if (philo->acts->eat_limit == 1)
		philo->eat_count--;
	pthread_mutex_unlock(philo->right_hand);
	pthread_mutex_unlock(philo->left_hand);
	if (ft_check_dead(philo) == 1)
		return (1);
	if (ft_print_message("is sleeping", philo, 0) == 0)
		usleep(philo->acts->time_sleep * 1000);
	ft_print_message("is thinking", philo, 0);
	usleep(200);
	return (0);
}

int	ft_even(t_philosophers *philo)
{
	if (ft_print_message("is thinking", philo, 0) == 0)
		usleep(200);
	if (ft_check_dead(philo) == 1)
		return (1);
	pthread_mutex_lock(philo->right_hand);
	if (ft_drop_one(philo, philo->right_hand) == 1)
		return (1);
	ft_print_message("has taken a fork", philo, 0);
	usleep(200);
	pthread_mutex_lock(philo->left_hand);
	if (ft_drop_two(philo) == 1)
		return (1);
	ft_print_message("has taken a fork", philo, 0);
	if (ft_print_message("is eating", philo, 1) == 1)
		return (ft_drop_two(philo));
	usleep(philo->acts->time_eat * 1000 + philo->acts->sleep_case);
	if (philo->acts->eat_limit == 1)
		philo->eat_count--;
	pthread_mutex_unlock(philo->right_hand);
	pthread_mutex_unlock(philo->left_hand);
	if (ft_check_dead(philo) == 1)
		return (1);
	if (ft_print_message("is sleeping", philo, 0) == 0)
		usleep(philo->acts->time_sleep * 1000);
	return (0);
}
