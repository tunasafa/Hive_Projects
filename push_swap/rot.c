/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:15:20 by stuna             #+#    #+#             */
/*   Updated: 2024/01/19 15:15:22 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}

void	finish_rotation(t_stack **s, t_stack *top, char s_name)
{
	while (*s != top)
	{
		if (s_name == 'a')
		{
			if (top->upordown == 1)
				ra(s);
			else
				rra(s);
		}
		else if (s_name == 'b')
		{
			if (top->upordown == 1)
				rb(s);
			else
				rrb(s);
		}
	}
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rr(a, b);
	current_position(*a);
	current_position(*b);
}
