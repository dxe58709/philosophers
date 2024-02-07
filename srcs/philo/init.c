/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:28:07 by nsakanou          #+#    #+#             */
/*   Updated: 2024/02/07 20:39:49 by nsakanou         ###   ########.fr       */
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

//forkにunsignedは割り当てできない
void	init_philo_data(t_philo *philo)
{
	unsigned int	i;

	i = 0;
	while (i < philo->args.number_of_philo)
	{
		philo[i].philo_id = i + 1;
		philo[i].right_fork = i;
		philo[i].left_fork = (i + 1) % philo->args.number_of_philo;
		i++;
	}
}
