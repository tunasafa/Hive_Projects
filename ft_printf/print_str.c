/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:33:57 by stuna             #+#    #+#             */
/*   Updated: 2023/11/22 17:12:51 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	unsigned int	i;
	int				check;

	i = 0;
	check = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		check = putchar_printf(str[i]);
		if (check == -1)
			return (-1);
		i++;
	}
	return (i);
}
