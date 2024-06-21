/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:11:40 by stuna             #+#    #+#             */
/*   Updated: 2024/06/21 14:51:55 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	stop_simulation_flag_control(t_table *table)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock(&table->meal_checker_mutex);
	if (table->stop_simulation == 1)
		flag = 1;
	pthread_mutex_unlock(&table->meal_checker_mutex);
	return (flag);
}

void	update_stop_flag(t_table *table, int flag)
{
	pthread_mutex_lock(&table->meal_checker_mutex);
	table->stop_simulation = flag;
	pthread_mutex_unlock(&table->meal_checker_mutex);
}

static int	free_mutex(t_table *table)
{
	int	i;

	i = -1;
	if (!table)
		return (1);
	while (++i < table->number_philo)
	{
		if (table->return_mutex_fork)
			pthread_mutex_destroy(&table->fork_mutexes[i]);
		if (table->philo[i].return_mutex_eating)
			pthread_mutex_destroy(&table->philo[i].eating_mutex);
	}
	if (table->return_mutex_checker)
		pthread_mutex_destroy(&table->meal_checker_mutex);
	if (table->return_mutex_print)
		pthread_mutex_destroy(&table->print_mutex);
	free(table->philo);
	free(table->fork_mutexes);
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (arg_check(argc, argv) != 0)
		return (-1);
	if (set_table(&table, argc, argv))
		return (free_mutex(&table), 0);
	if (begin_life_cycle(&table))
		return (free_mutex(&table), 0);
	if (free_mutex(&table))
		return (0);
	return (0);
}
