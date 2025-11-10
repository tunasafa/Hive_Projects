/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:05:21 by stuna             #+#    #+#             */
/*   Updated: 2024/06/21 12:48:21 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_status(t_philo *philo, long long time, t_philo_status status)
{
	printf ("\033[33mtime : %lld \t", time);
	printf ("\033[36mphilo : %d \t", philo->id + 1);
	if (status == FORK1_IS_IN_USE)
		printf("\033[32mstate : has taken the left fork");
	else if (status == FORK2_IS_IN_USE)
		printf("\033[36mstate : has taken the right fork");
	else if (status == IS_EATING)
		printf("\033[35mstate : is eating");
	else if (status == IS_SLEEPING)
		printf("\033[33mstate : is sleeping");
	else if (status == IS_THINKING)
		printf("\033[37mstate : is thinking");
	else if (status == IS_DEAD)
		printf("\033[31mstate : is dead");
	printf("\033[0m\n");
}

void	log_philos(t_philo *philo, t_philo_status status, int dead)
{
	long long	temp;

	pthread_mutex_lock(&philo->table_rules->print_mutex);
	if (stop_simulation_flag_control(philo->table_rules) == 1 && dead == 0)
	{
		pthread_mutex_unlock(&philo->table_rules->print_mutex);
		return ;
	}
	temp = convert_miliseconds() - philo->table_rules->simulation_start_time;
	print_status(philo, temp, status);
	pthread_mutex_unlock(&philo->table_rules->print_mutex);
}

void	print_errors(t_table *table, char *msg)
{
	pthread_mutex_lock(&table->print_mutex);
	printf("\033[31m%s\033[0m\n", msg);
	pthread_mutex_unlock(&table->print_mutex);
}
