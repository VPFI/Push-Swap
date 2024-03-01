/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:09:46 by vperez-f          #+#    #+#             */
/*   Updated: 2024/03/01 18:16:22 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Do checks for invalid params before calling
// Stack funtions check at least 2 elements
void	first_sort(t_stack **a, t_stack **b, int argc)
{
	int	pivot;
	int	lo;

	argc = 0;
	pivot = a[0]->num;
	lo = pivot;
	rotate_a(a);
	while (a[0]->num != pivot && *a)
	{
		if (a[0]->num < pivot)
		{
			push_b(a, b);
			if (b[0]->num < lo)
			{
				lo = b[0]->num;
			}
		}
		else
			rotate_a(a);
	}
	printf("Low: %i\n", lo);
	while (*a)
	{
		push_b(a, b);
	}
	sort(a, b, argc, pivot);
}
void	sort(t_stack **a, t_stack **b, int argc, int prev_pivot)
{
	int	pivot;

	argc = 0;
	if (*a)	
	{
		pivot = a[0]->num;
	}
	if (*b)
	{
		pivot = b[0]->num;
		rotate_b(b);
		while (b[0]->num != prev_pivot && *b)
		{
			if (b[0]->num > pivot)
				push_a(a, b);
			else
				rotate_b(b);			
		}
		while (b[0]->num != pivot && *b)
			r_rotate_b(b);
		while (*b)
		{
			push_a(a, b);
		}
	}

}

