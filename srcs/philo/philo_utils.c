/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:33:30 by nsakanou          #+#    #+#             */
/*   Updated: 2024/02/08 16:19:37 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	get_current_time(void)
{
	unsigned int	ms;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	ms = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (ms);
}

void	print_message(char *str, t_philo *philo)
{
	if (!check_philo_die(philo))
	{
		pthread_mutex_lock(&philo->check_die->mutex);
		printf("%d%d%s\n", get_current_time(), philo->philo_id, str);
		pthread_mutex_unlock(&philo->check_die->mutex);
	}
}

int	ft_usleep(int ms, t_philo *philo)
{
	int	start;

	start = get_current_time();
	while ((get_current_time() - start) < ms && !check_philo_die(philo))
		usleep(50);
	return (0);
}
