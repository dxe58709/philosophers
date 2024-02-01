/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:22:03 by nsakanou          #+#    #+#             */
/*   Updated: 2024/02/01 19:00:51 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	check_philo_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->check_die->mutex);
	if (philo->check_die->philo_dead == 1)
	{
		pthread_mutex_unlock(&philo->check_die->mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->check_die->mutex);
	return (0);
}

int	takes_forks(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	if (!check_philo_die(philo))
		print_message("has taken a fork", philo);
	if (philo->philo_id % 2 == 0)
	{
		if (pthread_mutex_lock(philo->left_fork) != 0)
			return (pthread_mutex_unlock(philo->right_fork), 1);
		if (!check_philo_die(philo))
			print_message("has taken a fork", philo);
	}
	else
	{
		if (pthread_mutex_lock(philo->right_fork) != 0)
			return (pthread_mutex_unlock(philo->left_fork), 1);
		if (!check_philo_die(philo))
			print_message("has taken a fork", philo);
	}
	return (0);
}
