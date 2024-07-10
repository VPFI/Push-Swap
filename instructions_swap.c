/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:14:37 by vperez-f          #+#    #+#             */
/*   Updated: 2024/07/10 17:42:40 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **a)
{
	t_stack	*temp;

	if (*a)
	{
		temp = (a[0]->next)->next;
		ft_stackadd_front(a, a[0]->next);
		(a[0]->next)->next = temp;
	}
	write(1, "sa\n", 3);
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
	write(1, "sb\n", 3);
}

void	swap_all(t_stack **a, t_stack **b)
{
	swap_a(a);
	swap_b(b);
	write(1, "ss\n", 3);
}
