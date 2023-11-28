/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:42:54 by stuna             #+#    #+#             */
/*   Updated: 2023/11/24 16:57:56 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_num(int n)
{
	int	count;
	int	temp;

	count = 0;
	if (n == -2147483648)
	{
		if (print_str("-2147483648") == -1)
			return (-1);
		return (11);
	}
	if (n < 0)
	{
		if (putchar_printf('-') == -1)
			return (-1);
		n = -n;
		count++;
	}
	temp = print_unsgnd((unsigned int)n);
	if (temp == -1)
		return (-1);
	count += temp;
	return (count);
}
