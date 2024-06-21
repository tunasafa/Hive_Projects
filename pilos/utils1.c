/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:07:16 by stuna             #+#    #+#             */
/*   Updated: 2024/06/21 13:02:21 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (0);
	write(fd, s, ft_strlen(s));
	return (1);
}

int	arg_check(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd(ERR_ARGC, 2);
		return (1);
	}
	if (ft_atois(argv[1]) < 1)
	{
		ft_putstr_fd(ERR_ARG1, 2);
		return (1);
	}
	if (ft_atois(argv[2]) <= 0 || ft_atois(argv[3]) <= 0
		|| ft_atois(argv[4]) <= 0)
	{
		ft_putstr_fd(ERR_DIGIT, 2);
		return (1);
	}
	if (argc == 6)
	{
		if (ft_atois(argv[5]) <= 0)
		{
			ft_putstr_fd(ERR_DIGIT, 2);
			return (1);
		}
	}
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putstr_fd("-", fd);
		n = -n;
	}
	if (n <= 9)
		ft_putstr_fd(n + "0", fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	return ;
}
