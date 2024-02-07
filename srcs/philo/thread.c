/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:23:15 by nsakanou          #+#    #+#             */
/*   Updated: 2024/02/07 20:39:35 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	(void)arg;
	//スレッド処理
	return (NULL);
}

void	create_thread(t_philo *philo)
{
	unsigned int	i;

	i = 0;
	while (i < philo->args.number_of_philo)
	{
		pthread_create(&philo[i].thread, NULL, &routine, (void *)&philo[i]);
		i++;
	}
}

void	join_thread(t_philo *philo)
{
	unsigned int	i;

	i = 0;
	while (i < philo->args.number_of_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}
