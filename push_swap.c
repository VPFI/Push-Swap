/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:35:51 by vperez-f          #+#    #+#             */
/*   Updated: 2024/02/27 15:04:48 by vperez-f         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (!argc)
		return (1);	
	fill_stack(&stack_a, argc, argv);
	while (stack_a)
	{
		if (stack_a -> num)
			{
				printf("num: %i\n", stack_a -> num);
			}
		stack_a = stack_a -> next;
	}
}
