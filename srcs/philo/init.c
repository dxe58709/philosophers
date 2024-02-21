/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:28:07 by nsakanou          #+#    #+#             */
/*   Updated: 2024/02/21 20:16:32 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_args(int argc, char **argv, t_args *args)
{
	args->number_of_philo = philo_atoi(argv[1]);
	args->time_to_die = philo_atoi(argv[2]);
	args->time_to_eat = philo_atoi(argv[3]);
	args->time_to_sleep = philo_atoi(argv[4]);
	if (argc == 6)
		args->number_of_eat = philo_atoi(argv[5]);
	else
		args->number_of_eat = -1;
}

void	init_philo_data(t_philo *philo, t_args args, pthread_mutex_t *forks)
{
	unsigned int	i;

	i = 0;
	while (i < args.number_of_philo)
	{
		philo[i].philo_id = i + 1;
		philo[i].count_eaten = 0;
		philo[i].right_fork = &forks[i];
		philo[i].left_fork = &forks[(i + 1) % args.number_of_philo];
		philo[i].last_meal_time = get_current_time();
		pthread_mutex_init(philo[i].count_eaten_mutex, NULL);
		pthread_mutex_init(philo[i].last_meal_time_mutex, NULL);
		i++;
	}
}
