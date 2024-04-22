/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:07:15 by stuna             #+#    #+#             */
/*   Updated: 2024/04/12 13:33:28 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_signal(int pid, unsigned char ch)
{
	int	i;
	int	pidcheck;

	pidcheck = 0;
	i = 0;
	while (i < 8)
	{
		if (ch << i & 0b10000000)
			pidcheck = kill(pid, SIGUSR1);
		else
			pidcheck = kill(pid, SIGUSR2);
		i++;
		usleep(99);
	}
	if (pidcheck == -1)
	{
		ft_putstr("\n\033[31m***** WRONG PID!!! *****   \n\n");
		ft_putstr("- Check the Server PID and enter it correctly!\033[0\n");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	int			pid;
	const char	*str;
	int			i;

	if (argc != 3)
	{
		ft_putstr("\n\033[31m*** WRONG INPUT FORM ***\033[0\n");
		ft_putstr("\n\033[31mUSAGE : ./client <PID> <STRING>\n\n");
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	i = 0;
	while (str[i] != '\0')
		send_signal(pid, str[i++]);
	send_signal(pid, '\0');
	return (0);
}
