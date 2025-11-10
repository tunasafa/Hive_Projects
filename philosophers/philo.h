/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:57:39 by stuna             #+#    #+#             */
/*   Updated: 2024/06/21 13:01:28 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

# define ERR_ARGC "Error: Incorrect number of arguments.\n \033[33m\n\tUsage : ./philo <Philosophers> \
<TimeToDie> <TimeToEat> <TimeToSleep> \
<NrOfTimesEachPhiloNeedsToEat(optional)>\n"
# define ERR_DIGIT "Error: Arguments must be in the \
range of positive integers.\n"
# define ERR_ARG1 "Error: Incorrect amount of philosophers.\n"
# define MLC_FL	"Malloc Fail "

# define NO 0
# define YES 1
# define FAILURE 1
# define SUCCESS 0
# define ERR_FILENO 2
# define UNSIGNED_INT_MAX 4294967295

# define ERR_INIT_TABLE "\n\tInitialization Error : \
Table initialization failure\n"
# define ERR_INIT_MUTEX "\n\tInitialization Error : \
Mutex initialization failure\n"
# define ERR_INIT_PHILO "\n\tInitialization Error : \
Philosopher initialization failure\n"
# define ERR_JOIN_THREAD "\n\tThread Error : Failed to join new thread\n"
# define ERR_THREAD "\n\tThread Error : Failed to create new thread\n"
# define ERR_USE "\033[33m\n\tUsage : ./philo <number1> <number2> <number3> \
<number4> <number5>\n"
# define ERR_ARG "\033[31m\n\tParameter Error : Invalid number of parameters\n"
# define ERR_NUM "\033[31m\n\tNumber Error : Non-positive or non-zero numbers\n"

typedef struct s_philo
{
	unsigned int	id;
	unsigned int	forks[2];
	pthread_mutex_t	eating_mutex;
	unsigned int	meals_count;
	long long		time_to_meal;
	int				return_mutex_eating;
	pthread_t		thread;
	struct s_table	*table_rules;
}	t_philo;

typedef struct s_table
{
	int				number_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meal_count_limit;
	int				stop_simulation;
	pthread_t		meal_checker;
	long long		simulation_start_time;
	int				return_mutex_fork;
	int				return_mutex_checker;
	int				return_mutex_print;
	pthread_mutex_t	*fork_mutexes;
	pthread_mutex_t	meal_checker_mutex;
	pthread_mutex_t	print_mutex;
	t_philo			*philo;
}	t_table;

typedef enum e_philo_status
{
	FORK1_IS_IN_USE,
	FORK2_IS_IN_USE,
	IS_DEAD,
	IS_THINKING,
	IS_EATING,
	IS_SLEEPING,
}	t_philo_status;

/* utils.c utils1.c */
int			ft_strlen(char *str);
int			ft_putstr_fd(char *s, int fd);
int			ft_atois(char *str);
int			arg_check(int argc, char **argv);
void		ft_putnbr_fd(int n, int fd);
/* time.c */
long long	convert_miliseconds(void);
void		wait_miliseconds(long long time);
void		stop_until(t_table *table, time_t additional_time);
/* threading.c */
int			begin_life_cycle(t_table *table);
/* inti.c */
int			set_table(t_table *table, int argc, char **argv);
/* check.c */
void		*checker(void *argument);
/* main.c */
int			stop_simulation_flag_control(t_table *table);
void		update_stop_flag(t_table *table, int flag);
/* print_status.c */
void		print_errors(t_table *table, char *msg);
void		log_philos(t_philo *philo, t_philo_status status, int dead);
/* cycle.c */
void		*philo_life(void *argument);

#endif
