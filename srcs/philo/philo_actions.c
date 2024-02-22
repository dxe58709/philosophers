/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:14:13 by nsakanou          #+#    #+#             */
/*   Updated: 2024/02/22 15:44:31 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	philo_eating(t_philo *philo)
{
	print_message("is eating", philo);
	pthread_mutex_lock(&philo->check_die->mutex);
	philo->last_meal_time = get_current_time() - philo->starting_time;
	philo->args.time_to_die = philo->last_meal_time + philo->args.time_to_die;
	pthread_mutex_unlock(&philo->check_die->mutex);
	ft_usleep(philo->args.time_to_eat, philo);
	pthread_mutex_lock(&philo->check_die->mutex);
	if (philo->args.number_of_eat != -1)
		philo->count_eaten++;
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(&philo->check_die->mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_sleeping(t_philo *philo)
{
	print_message("is sleeping", philo);
	ft_usleep(philo->args.time_to_sleep, philo);
}

void	philo_thinking(t_philo *philo)
{
	print_message("is thinking", philo);
}
