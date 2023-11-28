/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:21:02 by stuna             #+#    #+#             */
/*   Updated: 2023/11/23 13:48:51 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	lessthan10(unsigned int n)
{
	if (n < 10)
	{
		if (putchar_printf('0' + n) == -1)
			return (-1);
	}
	else
	{
		if (putchar_printf(('a' + (n - 10))) == -1)
			return (-1);
	}
	return (1);
}

int	print_hex_s(unsigned int n)
{
	int	count;
	int	check;

	count = 0;
	check = 0;
	if (n < 16)
	{
		check = lessthan10(n);
		if (check == -1)
			return (-1);
		count += check;
	}
	else
	{
		check = print_hex_s(n / 16);
		if (check == -1)
			return (-1);
		count += check;
		check = print_hex_s(n % 16);
		if (check == -1)
			return (-1);
		count += check;
	}
	return (count);
}
