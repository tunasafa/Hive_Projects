/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:15:57 by stuna             #+#    #+#             */
/*   Updated: 2024/01/19 15:15:59 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacklast(t_stack *s)
{
	if (!s)
		return (NULL);
	while (s->next)
		s = s->next;
	return (s);
}

t_stack	*ft_stacknew(long long content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
	{
		return (NULL);
	}
	new->val = content;
	new->next = NULL;
	new->position = -1;
	new->upordown = -1;
	new->price = -1;
	new->cheapest = -1;
	new->target = NULL;
	return (new);
}

void	ft_stackadd_back(t_stack **s, t_stack *new)
{
	t_stack	*temp;

	if (!new)
		return ;
	if (*s == NULL)
	{
		*s = new;
		return ;
	}
	temp = ft_stacklast(*s);
	temp->next = new;
}

int	stack_len(t_stack *s)
{
	int	i;

	i = 0;
	while (s)
	{
		s = s->next;
		i++;
	}
	return (i);
}
