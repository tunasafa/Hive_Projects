/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsgnd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:38:14 by stuna             #+#    #+#             */
/*   Updated: 2023/11/22 20:13:18 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsgnd(unsigned int n)
{
	int	count;
	int	check;

	count = 0;
	check = 0;
	if (n <= 9)
	{
		if (putchar_printf(n + '0') == -1)
			return (-1);
		count++;
	}
	else
	{
		check = print_unsgnd(n / 10);
		if (check == -1)
			return (-1);
		count += check;
		check = print_unsgnd(n % 10);
		if (check == -1)
			return (-1);
		count += check;
	}
	return (count);
}
