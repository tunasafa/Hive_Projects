/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:43:57 by stuna             #+#    #+#             */
/*   Updated: 2024/06/21 12:56:37 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	convert_miliseconds(void)
{
	struct timeval	time_value;

	gettimeofday(&time_value, NULL);
	return ((time_value.tv_sec * 1000) + (time_value.tv_usec / 1000));
}

void	wait_miliseconds(long long time)
{
	while (convert_miliseconds() < time)
		continue ;
}

void	stop_until(t_table *table, time_t additional_time)
{
	long long	time_to_wait;

	time_to_wait = convert_miliseconds() + additional_time;
	while (convert_miliseconds() < time_to_wait)
	{
		if (stop_simulation_flag_control(table) == 1)
			break ;
		usleep(100);
	}
}
