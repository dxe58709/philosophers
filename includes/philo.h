/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:49:14 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/30 20:15:27 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FHILO_H
# define FHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct	s_philo
{
	pthread_t		thread_id;
	int				philosoper_id;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
}t_philo;

#endif