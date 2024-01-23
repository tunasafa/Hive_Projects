/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:07:34 by stuna             #+#    #+#             */
/*   Updated: 2024/01/19 15:07:37 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s)
{
	if (s == NULL || s->next == NULL)
		return (0);
	while (s->next != NULL)
	{
		if (s->val > (s->next)->val)
			return (0);
		s = s->next;
	}
	return (1);
}

int	highest(t_stack *s)
{
	t_stack	*first;
	t_stack	*sec;
	t_stack	*thrd;

	first = s;
	sec = s->next;
	thrd = sec->next;
	if ((first->val > sec->val) && (first->val > thrd->val))
		return (1);
	else if ((sec->val > thrd->val) && (sec->val > first->val))
		return (2);
	else
		return (3);
}
