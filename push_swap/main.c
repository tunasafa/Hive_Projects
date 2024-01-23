/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:11:00 by stuna             #+#    #+#             */
/*   Updated: 2024/01/19 15:11:01 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	start_init(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	if (error_handling(argc, argv) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

static void	sorting(t_stack **a, t_stack **b)
{
	if (!is_sorted(*a))
	{
		if (stack_len(*a) <= 3)
			small_sorts(a);
		else
			push_swap(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;

	if (start_init(argc, argv) == 1)
		return (1);
	a = malloc(sizeof(t_stack));
	if (!a)
		return (1);
	*a = NULL;
	b = malloc(sizeof(t_stack));
	if (!b)
	{
		free(a);
		return (1);
	}
	*b = NULL;
	stack_init(a, argc, argv);
	sorting(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
