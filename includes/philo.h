/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:49:14 by nsakanou          #+#    #+#             */
/*   Updated: 2024/02/08 16:15:43 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>

// struct s_table
// {
// 	time_t start_time;
// 	t_args args;
// 	t_philo **philos;
// 	pthread_mutex_t *forks;
// };

typedef struct s_check_die
{
	pthread_mutex_t	mutex;//哲学者の死亡状態を保護するため
	int				philo_dead;//哲学者が死亡した場合に1、死亡していない場合に0のフラグ
}t_check_die;

typedef struct s_args
{
	unsigned int	number_of_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	number_of_eat;
}t_args;

typedef struct s_philo
{
	pthread_t		thread;
	unsigned int	philo_id;//自分の番号
	t_args			args;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_check_die		*check_die;
}t_philo;

//actions
int				check_philo_die(t_philo *philo);
void			philo_eating(t_philo *philo);
void			philo_sleeping(t_philo *philo);
void			philo_thinking(t_philo *philo);

//utils
unsigned int	get_current_time(void);
void			print_message(char *str, t_philo *philo);
int				ft_usleep(int ms, t_philo *philo);

//atoi
int				philo_atoi(char *str);

//init
void			init_args(int argc, char **argv, t_args *args);
void			init_philo_data(t_philo *philo, pthread_mutex_t *forks);

#endif