/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:09:46 by vperez-f          #+#    #+#             */
/*   Updated: 2024/03/15 21:39:31 by vperez-f         ###   ########.fr       */
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

void	good_sort_a(t_stack **a, t_stack **b, t_stack **ordered, int argc, int top, int bot, int pivot_index, int *count)
{
	int		pivot;
	t_stack *temp;

	temp = *ordered;

	printf("ENTRY A bot: %i --- A top: %i --- pv: %i\n", bot, top, pivot_index);
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
			*count++;
		}
		if (*a)
		{
			rotate_a(a);
		}
		*count++;
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
			*count++;
		}
		/*if ((*a)->num == pivot)
		{
			push_b(a, b);
			*count++;
		}*/
		bot = pivot_index;
		pivot_index = (top + pivot_index) / 2;
		//printf("END A bot: %i --- A top: %i --- pv: %i\n", bot, top, pivot_index);
		//printf("NUMMMMMM: %i TOP: %i -- BOT: %i -- Pivot_Index: %i --- Pivot: %i\n", (*a)->num, top, bot, pivot_index, pivot);
		//printf("Count: %i\n", *count);
		good_sort_a(a, b, ordered, argc, top, bot, pivot_index, count);
		good_sort_b(a, b, ordered, argc, (pivot_index - 1), bot, bot, count);
	}
}
void	good_sort_b(t_stack **a, t_stack **b, t_stack **ordered, int argc, int top, int bot, int pivot_index, int *count)
{
	int		pivot;
	int		kek;
	int		bot_num;
	int		return_num;

	argc = 0;
	pivot_index = (top + bot) / 2;
	pivot = get_pivot(ordered, pivot_index);
	bot_num = get_bot(ordered, bot);
	return_num = pivot;
	kek = top - bot;
	//printf("B top: %i --- bot: %i ---- kek: %i\n", top, bot, kek);
	//printf("DIV: %i\n",(top + bot) / 2);
	// Make function to sort optimized for 3?¿
	//print_stacks(a, b, ordered);
	if (*b && bot < top && (top - bot) > 1)
	{
		//printf("Pivot: %i ---- Bot_num: %i\n", pivot, bot_num);
		while ((*b)->num != pivot)
		{
			//printf("bbb%i\n", pivot);
			if ((*b)->num > pivot)
			{
				push_a(a, b);
			}
			else
			{
				return_num = (*b)->num;
				rotate_b(b);
				break;
			}
		}
		while ((*b)->num != pivot)
		{
			if ((*b)->num > pivot)
			{
				push_a(a, b);
			}
			else
			{
				rotate_b(b);
			}
		}
		//printf("cccc%i ---- %i\n", return_num, pivot);
		*count++;
		if (*b)
		{
			rotate_b(b);
		}
		*count++;
		while (*b && (*b)->num != bot_num)
		{
			//printf("aaaaaa%i\n", pivot);
			if ((*b)->num > pivot)
			{
				push_a(a, b);
			}
			else
			{
				rotate_b(b);
			}
			*count++;
		}
		while (*b && (*b)->num != return_num)
		{
			//printf("cccc%i\n", return_num);
			if ((*b)->num == pivot)
				push_a(a, b);
			r_rotate_b(b);
		}
		if (*a && (*a)->num == pivot)
			push_b(a, b);
		//printf("Count B: %i\n", *count);
		/*
		if (pivot_index != 0)
		*/
		//bot = pivot_index;
		//pivot_index = (pivot_index) / 2;
		//push_a(a, b);
		//print_stacks(a, b, ordered);
		//printf("TO ALT: TOP: %i -- BOT: %i -- Pivot_Index: %i\n", bot, top, pivot_index);
		good_sort_alt(a, b, ordered, argc, pivot_index + 1, top, pivot_index, count);
		good_sort_b(a, b, ordered, argc, pivot_index, bot, pivot_index, count);
		//print_stacks(a, b, ordered);
	}
	else
	{	
		while (*b && (*b)->num >= bot_num)
		{
			push_a(a, b);
			*count++;
		}
		//printf("Pushed till: [%i]\n", bot_num);
	}
	//make another func to do the till zero
}
void	good_sort_alt(t_stack **a, t_stack **b, t_stack **ordered, int argc, int top, int bot, int pivot_index, int *count)
{
	int		pivot;
	int		bot_num;
	int		return_num;

	pivot_index = (top + bot) / 2;
	pivot = get_pivot(ordered, pivot_index);
	bot_num = get_bot(ordered, bot);
	return_num = pivot;
	//printf("Alt bot: %i --- Alt top: %i --- Pivot: %i\n", bot, top, (top + bot) / 2);
	//printf("Count Before alt: %i\n", *count);
	//print_stacks(a, b, ordered);
	if (*a && top < bot && (bot - top) > 1)
	{
		//printf("num: %i -- bot: %i --- pv: %i\n", (*a)->num, bot_num, pivot);
		while ((*a)->num != pivot)
		{
			//printf("num: %i -- bot: %i --- pv: %i\n", (*a)->num, bot, pivot);
			if ((*a)->num < pivot)
			{
				push_b(a, b);
			}
			else
			{
				return_num = (*a)->num;				
				rotate_a(a);
				break;
			}
			*count++;
		}
		while ((*a)->num != pivot)
		{
			//printf("num: %i -- bot: %i --- pv: %i\n", (*a)->num, bot, pivot);
			if ((*a)->num < pivot)
				push_b(a, b);
			else
				rotate_a(a);
			*count++;
		}
		if (*a)
		{
			rotate_a(a);
		}
		*count++;
		while (*a && (*a)->num != bot_num)
		{
			//printf("Num: %i --- PV: %i\n", (*a)->num, pivot);
			if ((*a)->num < pivot)
			{
				push_b(a, b);
			}
			else
			{
				rotate_a(a);
			}
			*count++;
		}
		////s(a, b, ordered);
		while (*a && (*a)->num != return_num)
		{
			//printf("cccc%i\n", return_num);
			if ((*a)->num == pivot)
				push_b(a, b);
			r_rotate_a(a);
		}
		if (*b && (*b)->num == pivot)
			push_a(a, b);
		bot = pivot_index;
		pivot_index = (top + pivot_index) / 2;
		//printf("Count after alt: %i\n", *count);
		//printf("TOP_ALT: %i -- BOT: %i -- Pivot_Index: %i --- Pivot: %i\n", top, bot, pivot_index, pivot);
		//print_stacks(a, b, ordered);
		good_sort_alt(a, b, ordered, argc, pivot, bot, pivot_index, count);
		//printf("TO B: TOP: %i -- BOT: %i -- Pivot_Index: %i\n", top, bot, pivot_index);
		//push_b(a, b);
		//good_sort_b(a, b, ordered, argc, top, bot, pivot_index, count);
	}
	else
		bot = bot;
}