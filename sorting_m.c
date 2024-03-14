/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:09:46 by vperez-f          #+#    #+#             */
/*   Updated: 2024/03/14 22:42:07 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Do checks for invalid params before calling
// Stack funtions check at least 2 elements
/*
void	first_sort(t_stack **a, t_stack **b, t_stack **ordered, int argc)
{
	int	pivot;
	int	lo;
	int	hi;

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
	while (*a)
	{
		push_b(a, b);
	}
	printf("-----------------------------------------\n");
	printf("FIRST || Pivot A: %i\n", pivot);
	printf("-----------------------------------------\n");
	print_stacks(a, b);
	sort(a, b, argc, pivot, 1, pivot, hi, lo);
}*/
/*
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
		if (*b && b[0]->num != prev_pivot)
		{
			push_a(a, b);
		}
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
		if (side == 1)
		{
			while (*a)
			{
				push_b(a, b);
			}
		}
		printf("---------------------------------\n");
	}
}*/

void	good_sort_a(t_stack **a, t_stack **b, t_stack **ordered, int argc, int top, int bot, int pivot_index, int count)
{
	int		pivot;
	t_stack *temp;

	temp = *ordered;

	//printf("A bot: %i --- pv: %i\n", bot, pivot_index);
	//printf("A top: %i --- pv: %i\n", top, pivot_index);
	if (*a && pivot_index != bot)
	{
		//print_stacks(a, b, ordered);
		while (temp->index != pivot_index)
		{
			temp = temp->next;
		}
		pivot = temp->num;
		while ((*a)->num != pivot)
		{
			//printf("hola\n");
			//printf("num: %i -- bot: %i --- pv: %i\n", (*a)->num, bot, pivot);
			if ((*a)->num < pivot)
				push_b(a, b);
			else
				rotate_a(a);
			count++;
		}
		if (*a)
		{
			rotate_a(a);
		}
		count++;
		while (*a && (*a)->num != pivot)
		{
			if ((*a)->num < pivot)
			{
				//printf("Num: %i --- PV: %i\n", (*a)->num, pivot);
				push_b(a, b);
			}
			else
			{
				rotate_a(a);
			}
			count++;
		}
		printf("TOP: %i -- BOT: %i -- Pivot_Index: %i --- Pivot: %i\n", top, bot, pivot_index, pivot);
		bot = pivot_index;
		pivot_index = (argc + pivot_index) / 2;
		printf("Count: %i\n", count);
		good_sort_a(a, b, ordered, argc, top, bot, pivot_index, count);
		printf("TO B: TOP: %i -- BOT: %i -- Pivot_Index: %i\n", top, bot, pivot_index);
		push_b(a, b);
		good_sort_b(a, b, ordered, argc, top, bot, pivot_index, count);
	}
}
void	good_sort_b(t_stack **a, t_stack **b, t_stack **ordered, int argc, int top, int bot, int pivot_index, int count)
{
	int		pivot;
	t_stack *temp;

	temp = *ordered;
	argc = 0;
	//printf("B bot: %i --- pv: %i\n", bot, pivot_index);
	//printf("B top: %i --- pv: %i\n", top, pivot_index);
	print_stacks(a, b, ordered);
	if (*b && pivot_index != bot)
	{
		while (temp->index != pivot_index)
		{
			temp = temp->next;
		}
		pivot = temp->num;
		while ((*b)->num != pivot)
		{
			//printf("bbb%i\n", pivot);
			if ((*b)->num > pivot)
				push_a(a, b);
			else
				rotate_b(b);
			count++;
		}
		if (*b)
		{
			rotate_b(b);
		}
		count++;
		//printf("22num: %i -- top: %i --- pv: %i\n", (*b)->num, bot, pivot);
		//print_stacks(a, b, ordered);
		while (*b && (*b)->num != pivot)
		{
			if ((*b)->num > pivot)
			{
				push_a(a, b);
			}
			else
			{
				rotate_b(b);
			}
			count++;
		}
		printf("Count B: %i\n", count);
		/*
		if (pivot_index != 0)
		*/
		//bot = pivot_index;
		//pivot_index = (pivot_index) / 2;
		//push_a(a, b);
		
		printf("TO A: TOP: %i -- BOT: %i -- Pivot_Index: %i\n", top, bot, pivot_index);
		good_sort_alt(a, b, ordered, argc, top, bot, pivot_index, count);
	}
	//make another func to do the till zero
}
void	good_sort_alt(t_stack **a, t_stack **b, t_stack **ordered, int argc, int top, int bot, int pivot_index, int count)
{
	int		pivot;
	t_stack *temp;

	temp = *ordered;

	//printf("A bot: %i --- pv: %i\n", bot, pivot_index);
	//printf("A top: %i --- pv: %i\n", top, pivot_index);
	if (*a && pivot_index != bot)
	{
		//print_stacks(a, b, ordered);
		while (temp->index != pivot_index)
		{
			temp = temp->next;
		}
		pivot = temp->num;
		while ((*a)->num != pivot)
		{
			//printf("hola\n");
			//printf("num: %i -- bot: %i --- pv: %i\n", (*a)->num, bot, pivot);
			if ((*a)->num < pivot)
				push_b(a, b);
			else
				rotate_a(a);
			count++;
		}
		if (*a)
		{
			rotate_a(a);
		}
		count++;
		while (*a && (*a)->num != pivot)
		{
			if ((*a)->num < pivot)
			{
				//printf("Num: %i --- PV: %i\n", (*a)->num, pivot);
				push_b(a, b);
			}
			else
			{
				rotate_a(a);
			}
			count++;
		}
		printf("TOP: %i -- BOT: %i -- Pivot_Index: %i --- Pivot: %i\n", top, bot, pivot_index, pivot);
		bot = pivot_index;
		pivot_index = (argc + pivot_index) / 2;
		printf("Count: %i\n", count);
		good_sort_alt(a, b, ordered, argc, top, bot, pivot_index, count);
		printf("TO B: TOP: %i -- BOT: %i -- Pivot_Index: %i\n", top, bot, pivot_index);
		push_b(a, b);
		good_sort_b(a, b, ordered, argc, top, bot, pivot_index, count);
	}
}