/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intructions_r_rot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:39:45 by vperez-f          #+#    #+#             */
/*   Updated: 2024/07/10 17:15:19 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate_a(t_stack **a)
{
	t_stack	*new_last;

	if (*a)
	{
		new_last = (ft_stackbefore_last(*a));
		ft_stackadd_front(a, ft_stacklast(*a));
		new_last->next = NULL;
	}
	write(1, "rra\n", 4);
}

void	r_rotate_b(t_stack **b)
{
	t_stack	*new_last;

	if (*b)
	{
		new_last = (ft_stackbefore_last(*b));
		ft_stackadd_front(b, ft_stacklast(*b));
		new_last->next = NULL;
	}
	write(1, "rrb\n", 4);
}

void	r_rotate_all(t_stack **a, t_stack **b)
{
	t_stack	*new_last_a;
	t_stack	*new_last_b;

	new_last_a = NULL;
	new_last_b = NULL;
	if (*a)
	{
		new_last_a = (ft_stackbefore_last(*a));
		ft_stackadd_front(a, ft_stacklast(*a));
		new_last_a->next = NULL;
	}
	if (*b)
	{
		new_last_b = (ft_stackbefore_last(*b));
		ft_stackadd_front(b, ft_stacklast(*b));
		new_last_b->next = NULL;
	}
	write(1, "rrr\n", 4);
}
