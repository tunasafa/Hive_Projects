/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:32:29 by stuna             #+#    #+#             */
/*   Updated: 2024/01/19 15:35:10 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

static int	ft_char_to_int(char c)
{
	return ((int)(c - '0'));
}

int	ft_atoi(char *str)
{
	int		minus;
	long	number;

	minus = 1;
	number = 0;
	while (*str != '\0' && ft_isspace(*str) == 1)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-' && ft_isdigit(*(str + 1)))
		{
			number = -1 * ft_char_to_int(*(str + 1));
			minus = -1;
			str++;
		}
		str++;
	}
	while (*str != '\0' && ft_isdigit(*str) == 1)
	{
		number = number * 10 + minus * ft_char_to_int(*str);
		if (number / minus < 0)
			return ((minus > 0) * (-1));
		str++;
	}
	return (number);
}
