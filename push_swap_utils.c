/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:34:27 by vperez-f          #+#    #+#             */
/*   Updated: 2024/02/29 18:12:18 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b)
	{
		temp = (*b)->next;
		ft_stackadd_front(a, *b);
		b[0] = temp;
	}
}
void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*a)
	{
		temp = (*a)->next;
		ft_stackadd_front(b, *a);
		a[0] = temp;
	}
}
void	rotate_a(t_stack **a)
{
	t_stack	*new_last;

	if (*a)
	{
		new_last = (ft_stackbefore_last(*a));
		ft_stackadd_front(a, ft_stacklast(*a));
		new_last->next = NULL;
	}
}
void	rotate_b(t_stack **b)
{
	t_stack	*new_last;

	if (*b)
	{
		new_last = (ft_stackbefore_last(*b));
		ft_stackadd_front(b, ft_stacklast(*b));
		new_last->next = NULL;
	}
}
