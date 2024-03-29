/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:28:07 by nsakanou          #+#    #+#             */
/*   Updated: 2024/02/22 16:50:26 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_args(int argc, char **argv, t_philo *philo)
{
	philo->args.number_of_philo = philo_atoi(argv[1]);
	philo->args.time_to_die = philo_atoi(argv[2]);
	philo->args.time_to_eat = philo_atoi(argv[3]);
	philo->args.time_to_sleep = philo_atoi(argv[4]);
	if (argc == 6)
		philo->args.number_of_eat = philo_atoi(argv[5]);
	else
		philo->args.number_of_eat = -1;
}

void	init_philo_data(t_philo *philo, t_args args, pthread_mutex_t *forks)
{
	unsigned int	i;

	i = 0;
	while (i < args.number_of_philo)
	{
		philo[i].starting_time = get_current_time();
		philo[i].philo_id = i + 1;
		philo[i].count_eaten = 0;
		philo[i].right_fork = &forks[i];
		philo[i].left_fork = &forks[(i + 1) % args.number_of_philo];
		philo[i].last_meal_time = 0;
		pthread_mutex_init(philo[i].count_eaten_mutex, NULL);
		pthread_mutex_init(philo[i].last_meal_time_mutex, NULL);
		i++;
	}
}
