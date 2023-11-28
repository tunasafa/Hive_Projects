/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:45:12 by stuna             #+#    #+#             */
/*   Updated: 2023/11/23 11:27:59 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	longtohex(unsigned long long n)
{
	int	count;

	count = 0;
	if (n < 16)
	{
		if (n < 10)
		{
			if (putchar_printf(('0' + n)) == -1)
				return (-1);
			count++;
		}
		else
		{
			if (putchar_printf(('a' + (n - 10))) == -1)
				return (-1);
			count++;
		}
	}
	else
	{
		count += longtohex(n / 16);
		count += longtohex(n % 16);
	}
	return (count);
}

int	print_adrs(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (print_str("0x0"));
	count = print_str("0x");
	if (count == -1)
		return (-1);
	count += longtohex(ptr);
	if (count == -1)
		return (-1);
	return (count);
}
