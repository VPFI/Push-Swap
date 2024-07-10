/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:24:18 by vperez-f          #+#    #+#             */
/*   Updated: 2024/07/10 17:37:23 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int		first;
	int		second;
	int		third;
	t_stack	*temp;

	temp = *stack_a;
	first = temp->num;
	second = temp->next->num;
	third = temp->next->next->num;
	if (first < second && first < third)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (first > second && first < third)
		swap_a(stack_a);
	else if (first < second && first > third)
		r_rotate_a(stack_a);
	else if (second < third)
		rotate_a(stack_a);
	else if (second > third)
	{
		swap_a(stack_a);
		r_rotate_a(stack_a);
	}
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int		count;

	count = count_stack(*stack_a);
	while (3 < count)
	{
		if ((*stack_a)->index == 0)
		{
			push_b(stack_a, stack_b);
			count--;
		}
		else
			rotate_a(stack_a);
	}
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	push_a(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int		count;

	count = count_stack((*stack_a));
	while (3 < count)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
		{
			push_b(stack_a, stack_b);
			count--;
		}
		else
			rotate_a(stack_a);
	}
	if (!is_sorted((*stack_a)))
		sort_three(stack_a);
	if (is_sorted((*stack_b)))
		rotate_b(stack_b);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	radix_sort_b(int itr, int i, t_stack **stack_a, t_stack **stack_b)
{
	int	count;

	count = count_stack(*stack_b);
	while (*stack_b && !is_sorted(*stack_a) && count && i <= itr)
	{
		if ((((*stack_b)->index >> i) & 1) == 0)
			rotate_b(stack_b);
		else
			push_a(stack_a, stack_b);
		count--;
	}
	while (*stack_b && count)
	{
		push_a(stack_a, stack_b);
		count--;
	}
}

void	radix_sort_a(int amount, t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	iterations;
	int	count;

	iterations = 0;
	i = amount;
	while (i > 1 && ++iterations)
		i /= 2;
	i = 0;
	while (i <= iterations)
	{
		count = count_stack(*stack_a);
		while (*stack_a && !is_sorted(*stack_a) && count)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a);
			count--;
		}
		radix_sort_b(iterations, i + 1, stack_a, stack_b);
		i++;
	}
	while (*stack_b)
		push_a(stack_a, stack_b);
}
