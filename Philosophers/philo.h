/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:17:14 by yakhadad          #+#    #+#             */
/*   Updated: 2024/11/25 18:17:16 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct args	t_args;

typedef struct philosophers
{
	int				id;
	int				eat_count;
	long			last_meal_time;
	pthread_t		philo;
	pthread_mutex_t	*right_hand;
	pthread_mutex_t	*left_hand;
	t_args			*acts;
}					t_philosophers;

typedef struct args
{
	int				num_philo;
	int				time_death;
	int				time_eat;
	int				time_sleep;
	int				sleep_case;
	int				num_meals;
	int				eat_limit;
	int				philo_died;
	int				full_philos;
	long			start_time;
	pthread_t		monitor;
	pthread_mutex_t	full_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	msg_lock;
	pthread_mutex_t	*forks;
	t_philosophers	*philos;
}					t_args;

int					ft_atoi(char *str);
void				ft_error(char *str, t_args *acts);
void				*ft_monitor(void *my_struct);
int					ft_dead_philo(t_args *acts, int i);
int					ft_check_dead(t_philosophers *philo);
void				*ft_routine(void *my_struct);
int					ft_split_philos(t_philosophers *philo);
int					ft_print_message(char *str, t_philosophers *philo, int cas);
long				ft_get_time(t_args *acts);
int					ft_even(t_philosophers *philo);
int					ft_odd(t_philosophers *philo);
int					ft_one(t_philosophers *philo);
void				*ft_one_philo(t_philosophers *philo);
#endif
