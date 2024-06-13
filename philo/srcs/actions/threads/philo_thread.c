/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:28:56 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/13 17:29:42 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	create_philo_threads(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->args.number_of_philo)
	{
		create_thread(&data->threads[i], &philo_routine, &data->philo[i]);
		i++;
	}
	i = 0;
	while (i < data->args.number_of_philo)
	{
		join_thread(data->threads[i]);
		i++;
	}
	return (true);
}
