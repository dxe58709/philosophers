/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:22:03 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/30 18:39:08 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_one()
{
	if (one == food)
	{
		if (two == food)
		{
			//two_food_shori
		}
		else if (two == sleep)
		{
			//two_sleep_shori
		}
	}
}

void	fork_process(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	//error_shori
	if (pid == 0)
	//子プロセス
	else
	//親プロセス
}
