/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:09:18 by stuna             #+#    #+#             */
/*   Updated: 2024/01/19 15:09:20 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	repeat_num(int argc, char **argv, int i)
{
	int		j;
	size_t	size;

	j = 0;
	if (argc > 2)
		j++;
	while (argv[j] != NULL)
	{
		if (i != j)
		{
			size = ft_strlen(argv[i]);
			if (size < ft_strlen(argv[j]))
				size = ft_strlen(argv[j]);
			if (ft_strncmp(argv[i], argv[j], size) == 0)
				return (1);
		}
		j++;
	}
	return (0);
}

void	free_array(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

static int	error_check(int argc, char **argv, int i)
{
	int	j;

	j = 0;
	while (argv[i][j] != '\0')
	{
		if (correct_num(argv, i, j) == 1)
		{
			if (argc == 2)
				free_array(argv);
			return (1);
		}
		j++;
	}
	if (repeat_num(argc, argv, i) == 1)
	{
		if (argc == 2)
			free_array(argv);
		return (1);
	}
	return (0);
}

int	error_handling(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		i++;
	while (argv[i] != NULL)
	{
		if (error_check(argc, argv, i) == 1)
			return (1);
		i++;
	}
	if (argc == 2)
		free_array(argv);
	return (0);
}

void	free_stack(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*current;

	if (s == NULL)
		return ;
	current = *s;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free(s);
}
