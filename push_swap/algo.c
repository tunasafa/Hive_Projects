/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:07:02 by stuna             #+#    #+#             */
/*   Updated: 2024/01/19 15:07:04 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sorts(t_stack **s)
{
	int	len;

	len = stack_len(*s);
	if (len == 2)
		swap(s);
	if (len == 3)
	{
		if (highest(*s) == 1)
			ra(s);
		else if (highest(*s) == 2)
			rra(s);
		if ((*s)->val > ((*s)->next)->val)
			sa(s);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(a, b);
	}
}

t_stack	*return_cheapest(t_stack *s)
{
	if (s == NULL)
		return (NULL);
	while (s)
	{
		if (s -> cheapest == 1)
			return (s);
		s = s -> next;
	}
	return (NULL);
}

static void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = return_cheapest(*b);
	if (cheapest -> upordown == 1 && cheapest -> target -> upordown == 1)
		rotate_both(a, b, cheapest);
	else if (cheapest -> upordown == -1 && cheapest -> target -> upordown == -1)
		reverse_rotate_both(a, b, cheapest);
	finish_rotation(b, cheapest, 'b');
	finish_rotation(a, cheapest -> target, 'a');
	pa(a, b);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest;

	push_init(a, b);
	small_sorts(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	current_position(*a);
	smallest = find_smallest(*a);
	if (smallest -> upordown == 1)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}
