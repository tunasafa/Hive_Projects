/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:33:58 by stuna             #+#    #+#             */
/*   Updated: 2024/06/21 12:53:59 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_threads(t_table *table)
{
	int	i;

	i = 0;
	table->simulation_start_time = convert_miliseconds();
	while (i < table->number_philo)
	{
		if (pthread_create(&table->philo[i].thread,
				NULL, &philo_life, &table->philo[i]))
			return (1);
		i++;
	}
	if (table->number_philo > 1)
	{
		if (pthread_create(&table->meal_checker, NULL, &checker, table))
			return (1);
	}
	return (0);
}

static int	join_philo_threads(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->number_philo)
		pthread_join(table->philo[i].thread, NULL);
	if (table->number_philo > 1)
		pthread_join(table->meal_checker, NULL);
	return (0);
}

int	begin_life_cycle(t_table *table)
{
	if (philo_threads(table))
		return (print_errors(table, ERR_THREAD), 1);
	if (join_philo_threads(table))
		return (print_errors(table, ERR_JOIN_THREAD), 1);
	return (0);
}
