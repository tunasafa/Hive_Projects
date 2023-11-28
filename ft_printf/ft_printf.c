/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:49:21 by stuna             #+#    #+#             */
/*   Updated: 2023/11/23 12:33:41 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	formatcase(va_list args, const char *input)
{
	size_t	i;

	i = 0;
	if (input[i] == 'c')
		i += putchar_printf(va_arg(args, int));
	else if (input[i] == 's')
		i += print_str(va_arg(args, char *));
	else if (input[i] == 'p')
		i += print_adrs(va_arg(args, unsigned long long));
	else if (input[i] == 'd' || input[i] == 'i')
		i += print_num(va_arg(args, int));
	else if (input[i] == 'u')
		i += print_unsgnd(va_arg(args, unsigned int));
	else if (input[i] == 'x')
		i += print_hex_s(va_arg(args, unsigned int));
	else if (input[i] == 'X')
		i += print_hex_b(va_arg(args, unsigned int));
	else if (input[i] == '%')
		i += print_prcnt();
	return (i);
}

static int	printf_temp(const char *input, va_list args)
{
	size_t	i;
	size_t	len;
	int		return_value;

	i = 0;
	len = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			i++;
			return_value = formatcase(args, &input[i]);
			if (return_value == -1)
				return (-1);
			len += return_value;
		}
		else
		{
			if (putchar_printf(input[i]) == -1)
				return (-1);
			len++;
		}
		i++;
	}
	return (len);
}

int	ft_printf(const char *input, ...)
{
	va_list	ap;
	int		len;

	if (!input)
		return (-1);
	va_start(ap, input);
	len = printf_temp(input, ap);
	va_end(ap);
	return (len);
}
