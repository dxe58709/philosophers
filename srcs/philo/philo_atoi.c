/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:39:02 by nsakanou          #+#    #+#             */
/*   Updated: 2024/02/07 20:36:21 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "limits.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_intmax(int c)
{
	return (c > INT_MAX || c < '0');
}

int	philo_atoi(char *str)
{
	int	nb;
	int	flag;

	nb = 0;
	flag = -1;

	if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	if (ft_intmax(nb) || *str != '\0')
		return (flag);
	return (nb);
}
