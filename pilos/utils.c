/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:07:27 by stuna             #+#    #+#             */
/*   Updated: 2024/06/21 15:57:02 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	spaces(int n)
{
	size_t	i;

	if (n == 0)
		return (1);
	if (n < 0)
		i = 1;
	else
		i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa(int n)
{
	long int	nr;
	int			spc;
	char		*nbrstr;
	int			rmd;

	nr = n;
	spc = spaces(n);
	nbrstr = malloc(spc + 1);
	if (nbrstr == NULL)
		return (NULL);
	nbrstr[spc] = '\0';
	if (nr == 0)
		nbrstr[0] = '0';
	if (nr < 0)
	{
		nbrstr[0] = '-';
		nr = -nr;
	}
	while (nr != 0)
	{
		rmd = nr % 10;
		nbrstr[--spc] = rmd + '0';
		nr = nr / 10;
	}
	return (nbrstr);
}

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_atois(char *str)
{
	int		i;
	int		res;
	char	*temp;

	if (!str || !*str)
		return (-1);
	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	temp = ft_itoa(res);
	if (ft_strcmp(str, temp) != 0)
	{
		free(temp);
		return (-1);
	}
	free(temp);
	return (res);
}
