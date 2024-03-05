/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:09:46 by vperez-f          #+#    #+#             */
/*   Updated: 2024/03/05 20:07:11 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Do checks for invalid params before calling
// Stack funtions check at least 2 elements
void	first_sort(t_stack **a, t_stack **b, int argc)
{
	int	pivot;
	int	lo;
	int	hi;

	argc = 0;
	pivot = a[0]->num;
	lo = pivot;
	hi = pivot;
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
		{
			if (a[0]->num > hi)
				hi = a[0]->num;
			rotate_a(a);
		}
	}
	printf("Low: %i\n", lo);
	printf("High: %i\n", hi);
	/*while (*a)
	{
		push_b(a, b);
	}*/
	printf("-----------------------------------------\n");
	printf("FIRST || Pivot A: %i\n", pivot);
	printf("-----------------------------------------\n");
	print_stacks(a, b);
	sort(a, b, argc, pivot, 1, pivot, hi, lo);
}
void	sort(t_stack **a, t_stack **b, int argc, int prev_pivot, int side, int og_pivot, int hi, int lo)
{
	int	pivot;
	int	finished;

	finished = 0;
	if (prev_pivot > 1000 || argc > 10)
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
		if (*a && a[0]->num != prev_pivot)
		{
			push_b(a, b);
		}
		side = 1;
		if (prev_pivot == pivot)
		{
			if ( pivot == hi)
			{
				finished = 1;
			}
			else if (*a)
			{
				print_stacks(a, b);
				printf("-----------------------------\n");
				push_b(a, b);
				push_b(a, b);
				side = 0;
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
		/*if (*b && b[0]->num != prev_pivot)
		{
			push_a(a, b);
		}*/
		side = 0;
		if (prev_pivot == pivot)
		{
			if (pivot == hi)
			{
				finished = 1;
			}
			else if (*b)
			{
				print_stacks(a, b);
				printf("-----------------------------\n");
				push_a(a, b);
				push_a(a, b);
				side = 1;
			}
			else
				finished = 1;
		}
		print_stacks(a, b);
	}
	if (!finished)
	{
		argc++;
		printf(" %i ######## %i --- %i || %i || %i || %i || %i\n", argc, finished, side, pivot, prev_pivot, og_pivot, hi);
		sort(a, b, argc, pivot, side, og_pivot, hi, lo);
	}
	else
	{
		argc++;
		if (side == 0)
		{
			while (*b)
				{
					push_a(a, b);
				}
			sort(a, b, argc, pivot, side, og_pivot, hi, lo);
		}
		if (side == 1)
		{
			while (*a)
				{
					push_b(a, b);
				}
			sort(a, b, argc, pivot, side, og_pivot, hi, lo);
		}
	}
}
void	sort2(t_stack **a, t_stack **b, int argc, int prev_pivot, int side, int og_pivot, int lo)
{
	int	pivot;
	int	finished;

	finished = 0;
	if (prev_pivot > 500)
			return ;
	if (*a && side == 0)	
	{
		pivot = a[0]->num;
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
			finished = 1;
		}
		printf("-----------------------------------------\n");
		printf("Prev_Pivot B2: %i --- ", prev_pivot);
		printf("Pivot B2: %i\n", pivot);
		printf("-----------------------------------------\n");
		print_stacks(a, b);
	}
	if (!finished)
	{
		argc++;
		sort2(a, b, argc, pivot, side, og_pivot, lo);
	}
	else
	{
		argc++;
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
		printf("---------------------------------\n");
	}
}

