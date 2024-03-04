/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:35:51 by vperez-f          #+#    #+#             */
/*   Updated: 2024/03/04 20:34:13 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_stack **stack, int argc, char **argv)
{
	//check if (s)? and NULL nodes
	t_stack	*node;
	int		i;

	i = 1;
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
	int	i;
	t_stack *temp_a;
	t_stack *temp_b;

	i = 1;
	temp_a = *stack_a;
	temp_b = *stack_b;
	while (temp_a || temp_b)
	{
		if (temp_a)
		{
			if (temp_a->num)
				{
					printf("A[%02d]|| %02d --- ", i, temp_a -> num);
				}
			temp_a = temp_a -> next;
		}
		else
			printf("A[%02d]|| \\\\ --- ", i);
		if (temp_b)
		{
			if (temp_b -> num)
				{
					printf("%02d ||[%02d]B\n", temp_b -> num, i);
				}
			temp_b = temp_b -> next;
		}
		else
			printf("\\\\ ||[%02d]B\n", i);
		i++;
	}
}
int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!argc)
		return (1);	
	fill_stack(&stack_a, argc, argv);
	first_sort(&stack_a, &stack_b, argc);
	print_stacks(&stack_a, &stack_b);
}
