/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:33:35 by yakhadad          #+#    #+#             */
/*   Updated: 2024/10/10 13:33:38 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	ft_fill_philo_2(t_args *acts)
{
	int	i;

	acts->forks = NULL;
	acts->philos = malloc(sizeof(t_philosophers) * acts->num_philo);
	if (!acts->philos)
		ft_error("Memory allocation failed", acts);
	acts->forks = malloc(sizeof(pthread_mutex_t) * acts->num_philo);
	if (!acts->forks)
		ft_error("Memory allocation failed", acts);
	i = -1;
	while (++i < acts->num_philo)
	{
		acts->philos[i].acts = acts;
		acts->philos[i].last_meal_time = 0;
		acts->philos[i].id = i + 1;
		if (acts->eat_limit == 1)
			acts->philos[i].eat_count = acts->num_meals;
		else
			acts->philos[i].eat_count = 1;
		acts->philos[i].right_hand = &acts->forks[i];
		if (i != acts->num_philo - 1)
			acts->philos[i].left_hand = &acts->forks[i + 1];
		else
			acts->philos[i].left_hand = &acts->forks[0];
	}
}

void	ft_fill_philo(t_args *acts, char **av, int ac)
{
	acts->num_philo = ft_atoi(av[1]);
	if (acts->num_philo == 0)
		ft_error("there must be at least one philosopher", NULL);
	acts->time_death = ft_atoi(av[2]);
	acts->time_eat = ft_atoi(av[3]);
	acts->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		acts->num_meals = ft_atoi(av[5]);
		if (acts->num_meals == 0)
			ft_error("philosophers must eat at least once", NULL);
		acts->eat_limit = 1;
	}
	else
	{
		acts->num_meals = 0;
		acts->eat_limit = 0;
	}
	acts->philo_died = 0;
	acts->full_philos = 0;
	ft_fill_philo_2(acts);
}

void	ft_init_mutex(t_args *acts)
{
	int	i;

	i = -1;
	while (++i < acts->num_philo)
	{
		if (pthread_mutex_init(&acts->forks[i], NULL) != 0)
			ft_error("failed to initialize forks", acts);
	}
	if (pthread_mutex_init(&acts->full_lock, NULL) != 0
		|| pthread_mutex_init(&acts->dead_lock, NULL) != 0
		|| pthread_mutex_init(&acts->msg_lock, NULL) != 0)
		ft_error("failed to intialize lock", acts);
}

void	ft_create(t_args *acts)
{
	int	i;

	acts->start_time = ft_get_time(acts);
	if (pthread_create(&acts->monitor, NULL, ft_monitor, acts) != 0)
		ft_error("Failed to create threads", acts);
	i = -1;
	while (++i < acts->num_philo)
	{
		if (pthread_create(&acts->philos[i].philo, NULL, ft_routine,
				&acts->philos[i]) != 0)
			ft_error("Failed to create threads", acts);
		usleep(10);
	}
	if (pthread_join(acts->monitor, NULL))
		ft_error("Failed to join threads", acts);
	i = -1;
	while (++i < acts->num_philo)
	{
		if (pthread_join(acts->philos[i].philo, NULL) != 0)
			ft_error("Failed to join threads", acts);
	}
}

int	main(int ac, char **av)
{
	t_args	acts;

	if (ac != 5 && ac != 6)
		ft_error("Input error", NULL);
	ft_fill_philo(&acts, av, ac);
	ft_init_mutex(&acts);
	if (acts.num_philo % 2 == 0)
		acts.sleep_case = 150;
	else
		acts.sleep_case = 200;
	ft_create(&acts);
	free(acts.philos);
	free(acts.forks);
}
