/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:35:51 by vperez-f          #+#    #+#             */
/*   Updated: 2024/03/07 19:31:40 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack_ordered(t_stack **stack, int argc, char **argv)
{
	t_stack	*node;
	t_stack	*temp;
	int		i;

	i = 1;
	while ((argc - 1) > 0)
	{
		node = ft_stack_new(ft_atoi(argv[i]));
		if (stack)		
		{
			if (*stack)
			{
				temp = *stack;
				if (node->num < (temp)->num)
				{
					ft_stackadd_front(stack, node);
				}
				else
				{
					while (temp->next)
					{
						if (node->num > temp->num && (node->num < (temp->next)->num))
						{					
							node->next = temp->next;
							temp->next = node;
						}
						temp = temp->next;
					}
					if (node->num > temp->num && temp->next == NULL)
					{
						ft_stackadd_back(stack, node);
					}
				}
			}
			else
			{
				*stack = node;
			}
			i++;
			argc--;
		}
	}
	i = 1;
	temp = *stack;
	while (temp)
	{
		(temp)->index = i;
		temp = (temp)->next;
		i++;
	}
}
void	fill_stack(t_stack **stack, int argc, char **argv)
{
	//check if (s)? and NULL nodes
	t_stack	*node;
	int		i;

	i = 0;
	while ((argc - 1) > 0)
	{
		node = ft_stack_new(ft_atoi(argv[i]));
		ft_stackadd_back(stack, node);
		i++;
		argc--;
	}
}
void	print_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp_a;
	t_stack *temp_b;
	int		i;

	i = 1;
	temp_a = *stack_a;
	temp_b = *stack_b;
	while (temp_a || temp_b)
	{
		if (temp_a)
		{
			if (temp_a->num)
				{
					printf("A[%03d]|| %03d --- ", i, temp_a -> num);
				}
			temp_a = temp_a -> next;
		}
		else
			printf("A[%03d]|| \\\\ --- ", i);
		if (temp_b)
		{
			if (temp_b -> num)
				{
					printf("%03d ||[%03d]B\n", temp_b -> num, temp_b->index);
				}
			temp_b = temp_b -> next;
		}
		else
			printf("\\\\ ||[%03d]B\n", i);
		i++;
	}
}
int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack * ordered;
	//t_stack	*test;

	stack_a = NULL;
	stack_b = NULL;
	ordered = NULL;
	if (!argc)
		return (1);	
	fill_stack(&stack_a, argc, argv);
	fill_stack_ordered(&ordered, argc, argv);
	//first_sort(&stack_a, &stack_b, argc);
	print_stacks(&stack_a, &ordered);
	//test = ft_stacklast(stack_a);
	//printf("%i\n", test->num);
}
