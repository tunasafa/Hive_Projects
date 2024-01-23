/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:11:45 by stuna             #+#    #+#             */
/*   Updated: 2024/01/19 15:11:48 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*node;

	if (!(*s) || !((*s)->next))
		return ;
	tmp = *s;
	*s = (*s)->next;
	node = *s;
	while (node->next)
		node = node->next;
	node->next = tmp;
	tmp->next = NULL;
}

void	reverse_rotate(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*node;

	if (!(*s) || !((*s)->next))
		return ;
	tmp = ft_stacklast(*s);
	node = *s;
	while (node->next->next)
		node = node->next;
	node->next = NULL;
	tmp->next = *s;
	*s = tmp;
}

void	swap(t_stack **s)
{
	t_stack	*tmp;

	if (!(*s) || !((*s)->next))
		return ;
	tmp = *s;
	*s = (*s)->next;
	tmp->next = (*s)->next;
	(*s)->next = tmp;
}

void	push(t_stack **s1, t_stack **s2)
{
	t_stack	*tmp;

	if (!(*s2))
		return ;
	tmp = *s2;
	*s2 = (*s2)->next;
	tmp->next = *s1;
	*s1 = tmp;
}
