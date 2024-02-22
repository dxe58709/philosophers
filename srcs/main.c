/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:51:17 by nsakanou          #+#    #+#             */
/*   Updated: 2024/02/22 16:27:40 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (!(argc == 5 || argc == 6))
	{
		printf("argc_error.\n");
		return (false);
	}
	init_args(argc, argv, &philo);
	start_dinner(&philo);
	return (0);
}
