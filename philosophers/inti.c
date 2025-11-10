/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:24:16 by stuna             #+#    #+#             */
/*   Updated: 2024/06/21 14:50:16 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_table(int argc, char **argv, t_table *table)
{
	table->number_philo = ft_atois(argv[1]);
	table->fork_mutexes = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* table->number_philo);
	table->philo = (t_philo *)malloc(sizeof(t_philo) * table->number_philo);
	if (!table->fork_mutexes || !table->philo)
		return (1);
	table->time_to_die = ft_atois(argv[2]);
	table->time_to_eat = ft_atois(argv[3]);
	table->return_mutex_fork = 0;
	table->return_mutex_print = 0;
	table->return_mutex_checker = 0;
	table->time_to_sleep = ft_atois(argv[4]);
	table->stop_simulation = 0;
	table->meal_count_limit = -1;
	table->simulation_start_time = 0;
	if (argc == 6)
		table->meal_count_limit = ft_atois(argv[5]);
	else
		table->meal_count_limit = -1;
	return (0);
}

static int	init_philo(t_table *table)
{
	int	i;

	if (!table)
		return (1);
	i = -1;
	while (++i < table->number_philo)
	{
		table->philo[i].id = i;
		table->philo[i].meals_count = 0;
		table->philo[i].return_mutex_eating = 0;
		table->philo[i].thread = 0;
		table->philo[i].time_to_meal = table->simulation_start_time;
		table->philo[i].forks[0] = i;
		table->philo[i].forks[1] = ((i + 1) % table->number_philo);
		if (i % 2)
		{
			table->philo[i].forks[0] = ((i + 1) % table->number_philo);
			table->philo[i].forks[1] = i;
		}
		table->philo[i].table_rules = table;
	}
	return (0);
}

static int	init_mutexes(t_table *table)
{
	int	i;
	int	re_eat;
	int	re_fork;
	int	re_check;
	int	re_print;

	if (!table)
		return (1);
	i = table->number_philo;
	while (--i >= 0)
	{
		re_fork = pthread_mutex_init(&table->fork_mutexes[i], NULL);
		table->return_mutex_fork = re_fork;
		re_eat = pthread_mutex_init(&table->philo[i].eating_mutex, NULL);
		table->philo[i].return_mutex_eating = re_eat;
		if (re_fork != 0 || re_eat != 0)
			return (1);
	}
	re_check = pthread_mutex_init(&table->meal_checker_mutex, NULL);
	table->return_mutex_checker = re_check;
	re_print = pthread_mutex_init(&table->print_mutex, NULL);
	table->return_mutex_print = re_print;
	if (re_check != 0 || re_print != 0)
		return (1);
	return (0);
}

int	set_table(t_table *table, int argc, char **argv)
{
	if (init_table(argc, argv, table))
		return (print_errors(table, ERR_INIT_TABLE), 1);
	if (init_philo(table))
		return (print_errors(table, ERR_INIT_PHILO), 1);
	if (init_mutexes(table))
		return (print_errors(table, ERR_INIT_MUTEX), 1);
	return (0);
}
