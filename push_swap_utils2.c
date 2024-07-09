/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:39:45 by vperez-f          #+#    #+#             */
/*   Updated: 2024/03/01 16:57:17 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    r_rotate_a(t_stack **a)
{
	t_stack	*new_last;

	if (*a)
	{
		new_last = (ft_stackbefore_last(*a));
		ft_stackadd_front(a, ft_stacklast(*a));
		new_last->next = NULL;
	}
	printf("rra\n");
}
void    r_rotate_b(t_stack **b)
{
	t_stack	*new_last;

	if (*b)
	{
		new_last = (ft_stackbefore_last(*b));
		ft_stackadd_front(b, ft_stacklast(*b));
		new_last->next = NULL;
	}
	printf("rrb\n");
}
void    r_rotate_all(t_stack **a, t_stack **b)
{
    r_rotate_a(a);
    r_rotate_b(b);
	printf("rrr\n");
}
void	swap_a(t_stack **a)
{
	t_stack	*temp;

	if (*a)
	{
		temp = (a[0]->next)->next;
		ft_stackadd_front(a, a[0]->next);
		(a[0]->next)->next = temp;
	}
	printf("sa\n");
}
void	swap_b(t_stack **b)
{
	t_stack	*temp;

	if (*b)
	{
		temp = (b[0]->next)->next;
		ft_stackadd_front(b, b[0]->next);
		(b[0]->next)->next = temp;
	}
	printf("sba\n");
}
void	swap_all(t_stack **a, t_stack **b)
{
	swap_a(a);
	swap_b(b);
	printf("ss\n");
}
