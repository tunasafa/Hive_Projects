/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:14:17 by stuna             #+#    #+#             */
/*   Updated: 2024/01/21 13:05:19 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	long			val;
	int				position;
	int				upordown;
	int				price;
	int				cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

int		correct_num(char **argv, int i, int j);
void	free_array(char **argv);
int		error_handling(int argc, char **argv);
void	free_stack(t_stack **s);
t_stack	*ft_stacklast(t_stack *s);
t_stack	*ft_stacknew(long long content);
void	ft_stackadd_back(t_stack **s, t_stack *new);
int		stack_len(t_stack *s);
void	stack_init(t_stack **a, int argc, char **argv);
void	init_nodes(t_stack*a, t_stack *b);
void	push_init(t_stack **a, t_stack **b);
int		is_sorted(t_stack *s);
int		highest(t_stack *s);
void	current_position(t_stack *s);
t_stack	*find_smallest(t_stack *s);
void	find_target(t_stack *a, t_stack *b);
void	find_price(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *s);
void	rotate(t_stack **s);
void	reverse_rotate(t_stack **s);
void	swap(t_stack **s);
void	push(t_stack **s1, t_stack **s2);
void	sa(t_stack	**a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack**b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	finish_rotation(t_stack **s, t_stack *top, char s_name);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	small_sorts(t_stack **s);
void	sort_five(t_stack **a, t_stack **b);
t_stack	*return_cheapest(t_stack *s);
void	push_swap(t_stack **a, t_stack **b);

#endif
