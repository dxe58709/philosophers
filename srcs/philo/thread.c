/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:23:15 by nsakanou          #+#    #+#             */
/*   Updated: 2024/02/21 20:28:48 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (philo->check_die == 0)
	{
		if (check_philo_die(philo))
			return (0);
		takes_forks(philo);
		if (check_philo_die(philo))
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
			return (0);
		}
		philo_eating(philo);
		if (check_philo_die(philo))
			return (0);
		philo_sleeping(philo);
		if (check_philo_die(philo))
			return (0);
		philo_thinking(philo);
	}
	return (NULL);
}

void	start_dinner(t_philo *philo)
{
	unsigned int	i;

	i = 0;
	philo->starting_time = get_current_time();
	while (i < philo->args.number_of_philo)
	{
		pthread_create(&philo[i].thread, NULL,
			&philo_routine, (void *)&philo[i]);
		i++;
	}
	i = 0;
	while (i < philo->args.number_of_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}
