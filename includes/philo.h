/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:49:14 by nsakanou          #+#    #+#             */
/*   Updated: 2024/02/01 18:58:37 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FHILO_H
# define FHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_check_die
{
	pthread_mutex_t	mutex;//哲学者の死亡状態を保護するため
	int				philo_dead;//哲学者が死亡した場合に1、死亡していない場合に0のフラグ
}t_check_die;

typedef struct s_philo
{
	unsigned int	philo_id;//自分の番号
	unsigned int	philo_num;//人数
	unsigned int	die_time;
	unsigned int	sleep_time;
	unsigned int	eat_time;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_check_die		*check_die;
}t_philo;

unsigned int	get_current_time(void);
int				check_philo_die(t_philo *philo);
void			print_message(char *str, t_philo *philo);

#endif