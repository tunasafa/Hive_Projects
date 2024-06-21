/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:54:02 by stuna             #+#    #+#             */
/*   Updated: 2024/06/20 16:31:17 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	stop_check(t_philo *philo)
{
	long long	current;

	current = convert_miliseconds();
	if ((current - philo->time_to_meal) >= philo->table_rules->time_to_die)
	{
		update_stop_flag(philo->table_rules, YES);
		log_philos(philo, IS_DEAD, YES);
		pthread_mutex_unlock(&philo->eating_mutex);
		return (1);
	}
	return (0);
}

static int	check_termination(t_table *table)
{
	int			i;
	long long	meal_count;
	long long	meal_limit;
	int			eating_status;

	i = -1;
	eating_status = 1;
	while (++i < table->number_philo)
	{
		pthread_mutex_lock(&table->philo[i].eating_mutex);
		if (stop_check(&table->philo[i]) == 1)
			return (1);
		if (table->meal_count_limit != -1)
		{
			meal_count = (long long)table->philo[i].meals_count;
			meal_limit = (long long)table->meal_count_limit;
			if (meal_count < meal_limit)
				eating_status = 0;
		}
		pthread_mutex_unlock(&table->philo[i].eating_mutex);
	}
	if ((table->meal_count_limit != -1) && eating_status == 1)
		return (update_stop_flag(table, YES), 1);
	return (0);
}

void	*checker(void *argument)
{
	t_table	*table;

	if (!argument)
		return (NULL);
	table = (t_table *)argument;
	update_stop_flag(table, NO);
	wait_miliseconds(table->simulation_start_time);
	while (1)
	{
		if (check_termination(table) == 1)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
