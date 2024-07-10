/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:35:51 by vperez-f          #+#    #+#             */
/*   Updated: 2024/07/10 17:44:41 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit (1);
}

void	init_sort(int amount, t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	if (amount == 2)
		rotate_a(stack_a);
	else if (amount == 3)
		sort_three(stack_a);
	else if (amount == 4)
		sort_four(stack_a, stack_b);
	else if (amount == 5)
		sort_five(stack_a, stack_b);
	else
		radix_sort_a(amount, stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		amount;

	stack_a = NULL;
	stack_b = NULL;
	amount = argc - 1;
	if (argc < 2)
		return (1);
	if (invalid_args(argc, argv))
		error_exit();
	fill_stack(&stack_a, argc, argv);
	create_index(amount, argv, &stack_a);
	init_sort(amount, &stack_a, &stack_b);
	stack_lstclear(&stack_a);
	stack_lstclear(&stack_b);
	return (0);
}
