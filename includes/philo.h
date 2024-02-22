/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:49:14 by nsakanou          #+#    #+#             */
/*   Updated: 2024/02/22 16:47:01 by nsakanou         ###   ########.fr       */
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
# include <limits.h>

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
	int				number_of_eat;
}t_args;

typedef struct s_philo
{
	pthread_t		thread;
	unsigned int	philo_id;
	t_args			args;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	int				starting_time;
	unsigned int	last_meal_time;//各哲学者が最後に食事を終えた時間
	pthread_mutex_t	*last_meal_time_mutex;
	unsigned int	count_eaten;//各哲学者が食事を完了した回数
	pthread_mutex_t	*count_eaten_mutex;
	t_check_die		*check_die;
}t_philo;

//actions
int				check_philo_die(t_philo *philo);
int				takes_forks(t_philo *philo);
void			philo_eating(t_philo *philo);
void			philo_sleeping(t_philo *philo);
void			philo_thinking(t_philo *philo);

//utils
unsigned int	get_current_time(void);
void			print_message(char *str, t_philo *philo);
int				ft_usleep(unsigned int ms, t_philo *philo);

//atoi
int				philo_atoi(char *str);

//init
void			init_args(int argc, char **argv, t_philo *philo);
void			init_philo_data(t_philo *philo, t_args args,
					pthread_mutex_t *forks);
//thread
void			start_dinner(t_philo *philo);
#endif