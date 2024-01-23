/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:09:57 by stuna             #+#    #+#             */
/*   Updated: 2024/01/19 15:09:58 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack **a, int argc, char **argv)
{
	int		i;
	int		num;
	t_stack	*new;

	i = 0;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		i++;
	while (argv[i] != NULL)
	{
		num = ft_atoi(argv[i]);
		new = ft_stacknew(num);
		if (new == NULL)
		{
			free_stack(a);
			break ;
		}
		ft_stackadd_back(a, new);
		i++;
	}
	if (argc == 2)
		free_array(argv);
}

void	init_nodes(t_stack *a, t_stack *b)
{
	current_position(a);
	current_position(b);
	find_target(a, b);
	find_price(a, b);
	set_cheapest(b);
}

void	push_init(t_stack **a, t_stack **b)
{
	int		len_a;

	len_a = stack_len(*a);
	if (len_a <= 3)
		small_sorts(a);
	else if (len_a == 5)
		sort_five(a, b);
	else
	{
		while (len_a > 3)
		{
			pb(a, b);
			len_a--;
		}
	}
}
