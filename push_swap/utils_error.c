/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:08:10 by stuna             #+#    #+#             */
/*   Updated: 2024/01/19 15:08:15 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	not_num(char **argv, int i, int j)
{
	if (ft_isdigit(argv[i][j]) == 0)
	{
		if (argv[i][j] != '-' && argv[i][j] != '+')
			return (1);
		if ((argv[i][j] == '-' || argv[i][j] == '+') &&
				j != 0)
			return (1);
		if ((argv[i][j] == '-' || argv[i][j] == '+') &&
				argv[i][j + 1] == '\0')
			return (1);
	}
	return (0);
}

static int	not_pos_int(char **argv, int i, int j)
{
	if (j == 9 && argv[i][0] != '-' && argv[i][0] != '+' &&
			ft_strncmp(argv[i], "2147483647", 10) > 0)
		return (1);
	if (j > 9 && argv[i][0] != '-' && argv[i][0] != '+')
		return (1);
	if (j == 10 && argv[i][0] == '+' &&
			ft_strncmp(argv[i], "+2147483647", 11) > 0)
		return (1);
	if (j > 10 && argv[i][0] == '+')
		return (1);
	return (0);
}

static int	not_neg_int(char **argv, int i, int j)
{
	if (j == 10 && argv[i][0] == '-' &&
			ft_strncmp(argv[i], "-2147483648", 11) > 0)
		return (1);
	if (j > 10 && argv[i][0] == '-')
		return (1);
	return (0);
}

int	correct_num(char **argv, int i, int j)
{
	if (not_num(argv, i, j) == 1)
		return (1);
	if (not_pos_int(argv, i, j) == 1)
		return (1);
	if (not_neg_int(argv, i, j) == 1)
		return (1);
	return (0);
}
