/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:07:30 by stuna             #+#    #+#             */
/*   Updated: 2024/04/12 13:04:12 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	receive_char(int signal)
{
	static int	i;
	static char	c;

	if (signal == SIGUSR1)
		c = (c << 1) | 1;
	else if (signal == SIGUSR2)
		c = (c << 1);
	i++;
	if (i == 8)
	{
		if (c == '\0')
		{
			ft_putstr("\n");
		}
		else
			ft_putchar(c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr("\n\033[32m***| Server has Started |***\n\nServer PID : \033[0m");
	ft_putnbr(pid);
	ft_putstr("\n");
	signal(SIGUSR1, receive_char);
	signal(SIGUSR2, receive_char);
	while (1)
		pause();
	return (0);
}
