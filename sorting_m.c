/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:09:46 by vperez-f          #+#    #+#             */
/*   Updated: 2024/03/04 20:54:09 by vperez-f         ###   ########.fr       */
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
	while (*a && a[0]->num != pivot)
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
	printf("-----------------------------------------\n");
	printf("FIRST || Pivot A: %i\n", pivot);
	printf("-----------------------------------------\n");
	print_stacks(a, b);
	sort(a, b, argc, pivot, 1, pivot);
}
void	sort(t_stack **a, t_stack **b, int argc, int prev_pivot, int side, int og_pivot)
{
	int	pivot;
	int	finished;

	argc = 0;
	finished = 0;
	if (prev_pivot > 500)
			return ;
	if (*a && side == 0)	
	{
		pivot = a[0]->num;
		printf("-----------------------------------------\n");
		printf("Prev_Pivot A: %i --- ", prev_pivot);
		printf("Pivot A: %i\n", pivot);
		printf("-----------------------------------------\n");
		rotate_a(a);
		while (*a && (a[0]->num != prev_pivot && a[0]->num != pivot))
		{
			if (a[0]->num < pivot)
				push_b(a, b);
			else
				rotate_a(a);			
		}
		while (*a && a[0]->num != pivot)
			r_rotate_a(a);
		while (*a && a[0]->num != prev_pivot)
		{
			push_b(a, b);
		}
		side = 1;
		if (prev_pivot == pivot)
		{
			if (*b)
			{
				push_a(a, b);
				side = 1;
			}
			else
				finished = 1;
		}
		print_stacks(a, b);
	}
	else if (*b && side == 1)
	{
		pivot = b[0]->num;
		printf("-----------------------------------------\n");
		printf("Prev_Pivot B: %i --- ", prev_pivot);
		printf("Pivot B: %i\n", pivot);
		printf("-----------------------------------------\n");
		rotate_b(b);
		while (*b && (b[0]->num != prev_pivot && b[0]->num != pivot))
		{
			if (b[0]->num > pivot)
				push_a(a, b);
			else
				rotate_b(b);
		}
		while (*b && b[0]->num != pivot)
			r_rotate_b(b);
		while (*b && b[0]->num != prev_pivot)
		{
			push_a(a, b);
		}
		side = 0;
		if (prev_pivot == pivot)
		{
			if (*a)
			{
				push_b(a, b);
				side = 0;
			}
			else
				finished = 1;
		}
		print_stacks(a, b);
	}
	if (!finished)
	{
		printf("######## %i --- %i || %i || %i || %i\n", finished, side, pivot, prev_pivot, og_pivot);
		sort(a, b, argc, pivot, side, og_pivot);
	}
	else
	{
		if (side == 0)
		{
			while (*b)
				{
					push_a(a, b);
				}
			sort2(a, b, argc, pivot, side, og_pivot);
		}
		if (side == 1)
		{
			while (*a)
				{
					push_b(a, b);
				}
			sort2(a, b, argc, pivot, side, og_pivot);
		}
	}
}
void	sort2(t_stack **a, t_stack **b, int argc, int prev_pivot, int side, int og_pivot)
{
	int	pivot;
	int	finished;

	argc = 0;
	finished = 0;
	if (prev_pivot > 500)
			return ;
	if (*a && side == 0)	
	{
		pivot = a[0]->num;
		rotate_a(a);
		while (*a && a[0]->num != prev_pivot)
		{
			if (a[0]->num < pivot)
				push_b(a, b);
			else
				rotate_a(a);			
		}
		while (*a && a[0]->num != pivot)
			r_rotate_a(a);
		while (*a && a[0]->num != prev_pivot)
		{
			push_b(a, b);
		}
		side = 1;
		if (prev_pivot == pivot)
			finished = 1;
		printf("-----------------------------------------\n");
		printf("Prev_Pivot A2: %i --- ", prev_pivot);
		printf("Pivot A2: %i\n", pivot);
		printf("-----------------------------------------\n");
		print_stacks(a, b);
	}
	else if (*b && side == 1)
	{
		pivot = b[0]->num;
		rotate_b(b);
		while (*b && b[0]->num != prev_pivot)
		{
			if (b[0]->num > pivot)
				push_a(a, b);
			else
				rotate_b(b);
		}
		while (*b && b[0]->num != pivot)
			r_rotate_b(b);
		while (*b && b[0]->num != prev_pivot)
		{
			push_a(a, b);
		}
		side = 0;
		if (prev_pivot == pivot)
			finished = 1;
		printf("-----------------------------------------\n");
		printf("Prev_Pivot B2: %i --- ", prev_pivot);
		printf("Pivot B2: %i\n", pivot);
		printf("-----------------------------------------\n");
		print_stacks(a, b);
	}
	if (!finished)
	{
		sort2(a, b, argc, pivot, side, og_pivot);
	}
	else
	{
		printf("%i\n", side);
		if (side == 0 || side == 1)
		{
			while (*b)
			{
				push_a(a, b);
			}
		}
		/*
		if (side == 1)
		{
			while (*a)
			{
				push_b(a, b);
			}
		}*/
	}
}

