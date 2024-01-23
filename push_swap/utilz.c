/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilz.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:17:03 by stuna             #+#    #+#             */
/*   Updated: 2024/01/19 15:17:05 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_position(t_stack *s)
{
	int	i;
	int	median;

	i = 0;
	if (s == NULL)
		return ;
	median = stack_len(s) / 2;
	while (s)
	{
		s->position = i;
		if (i <= median)
			s->upordown = 1;
		else
			s->upordown = -1;
		s = s->next;
		i++;
	}
}

t_stack	*find_smallest(t_stack *s)
{
	int		smallest;
	t_stack	*smallest_node;

	if (s == NULL)
		return (NULL);
	smallest = INT_MAX;
	while (s)
	{
		if (s->val < smallest)
		{
			smallest = s->val;
			smallest_node = s;
		}
		s = s->next;
	}
	return (smallest_node);
}

void	find_target(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_n;
	int		biggest;

	while (b)
	{
		biggest = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if ((current_a->val > b->val) && (current_a->val < biggest))
			{
				biggest = current_a->val;
				target_n = current_a;
			}
			current_a = current_a->next;
		}
		if (biggest == INT_MAX)
			b->target = find_smallest(a);
		else
			b->target = target_n;
		b = b->next;
	}
}

void	find_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->price = b->position;
		if (b->upordown == -1)
			b->price = len_b - (b->position);
		if (b->target->upordown == 1)
			b->price += b->target->position;
		else
			b->price += len_a - (b->target->position);
		b = b->next;
	}
}

void	set_cheapest(t_stack *s)
{
	int		best_match_value;
	t_stack	*best_match_node;

	if (s == NULL)
		return ;
	best_match_value = INT_MAX;
	while (s)
	{
		if (s->price < best_match_value)
		{
			best_match_value = s->price;
			best_match_node = s;
		}
		s = s->next;
	}
	best_match_node->cheapest = 1;
}
