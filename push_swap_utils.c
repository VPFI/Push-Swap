/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:34:27 by vperez-f          #+#    #+#             */
/*   Updated: 2024/02/29 19:03:51 by vperez-f         ###   ########.fr       */
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
	t_stack	*new_first;

	if (*a)	
	{
		if (!((*a)->next))
			return ;
		new_first = a[0]->next;
		ft_stackadd_back(a, a[0]);
		(*a)->next = NULL;
		a[0] = new_first;
	}
}
void	rotate_b(t_stack **b)
{
	t_stack	*new_first;

	if (*b)	
	{
		if (!((*b)->next))
			return ;
		new_first = b[0]->next;
		ft_stackadd_back(b, b[0]);
		(*b)->next = NULL;
		b[0] = new_first;
	}
}
void	rotate_all(t_stack **a, t_stack **b)
{
	rotate_a(a);
	rotate_b(b);		
}
