/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:09:33 by stuna             #+#    #+#             */
/*   Updated: 2024/06/20 16:35:28 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eats(t_philo *philo)
{
	pthread_mutex_lock(&philo->table_rules->fork_mutexes[philo->forks[0]]);
	log_philos(philo, FORK1_IS_IN_USE, NO);
	pthread_mutex_lock(&philo->table_rules->fork_mutexes[philo->forks[1]]);
	log_philos(philo, FORK2_IS_IN_USE, NO);
	log_philos(philo, IS_EATING, NO);
	pthread_mutex_lock(&philo->eating_mutex);
	philo->time_to_meal = convert_miliseconds();
	pthread_mutex_unlock(&philo->eating_mutex);
	stop_until(philo->table_rules, philo->table_rules->time_to_eat);
	if (stop_simulation_flag_control(philo->table_rules) == 0)
	{
		pthread_mutex_lock(&philo->eating_mutex);
		philo->meals_count++;
		pthread_mutex_unlock(&philo->eating_mutex);
	}
	log_philos(philo, IS_SLEEPING, NO);
	pthread_mutex_unlock(&philo->table_rules->fork_mutexes[philo->forks[0]]);
	pthread_mutex_unlock(&philo->table_rules->fork_mutexes[philo->forks[1]]);
	stop_until(philo->table_rules, philo->table_rules->time_to_sleep);
}

static void	philo_think(t_philo *philo, int think_flag)
{
	long long	think_time;
	int			die_time;
	int			meal_time;
	int			eat_time;

	pthread_mutex_lock(&philo->eating_mutex);
	die_time = philo->table_rules->time_to_die;
	meal_time = convert_miliseconds() - philo->time_to_meal;
	eat_time = philo->table_rules->time_to_eat;
	think_time = (die_time - meal_time - eat_time) / 2;
	pthread_mutex_unlock(&philo->eating_mutex);
	if (think_time < 0)
		think_time = 0;
	if (think_time == 0 && think_flag == 1)
		think_time = 1;
	if (think_time > 600)
		think_time = 200;
	if (think_flag == 0)
		log_philos(philo, IS_THINKING, NO);
	stop_until(philo->table_rules, think_time);
}

static void	*one_philosopher(t_philo *philo)
{
	pthread_mutex_lock(&philo->table_rules->fork_mutexes[philo->forks[0]]);
	log_philos(philo, FORK1_IS_IN_USE, NO);
	stop_until(philo->table_rules, philo->table_rules->time_to_die);
	log_philos(philo, IS_DEAD, NO);
	pthread_mutex_unlock(&philo->table_rules->fork_mutexes[philo->forks[0]]);
	return (NULL);
}

void	*philo_life(void *argument)
{
	t_philo	*philo;
	t_table	*table;

	if (argument)
	{
		philo = (t_philo *)argument;
		table = philo->table_rules;
		pthread_mutex_lock(&philo->eating_mutex);
		philo->time_to_meal = table->simulation_start_time;
		pthread_mutex_unlock(&philo->eating_mutex);
		wait_miliseconds(table->simulation_start_time);
		if (table->number_philo == 1)
			return (one_philosopher(philo));
		else if (philo->id % 2)
			philo_think(philo, YES);
		while (stop_simulation_flag_control(table) == 0)
		{
			philo_eats(philo);
			philo_think(philo, NO);
		}
	}
	return (NULL);
}
