/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:18:40 by vperez-f          #+#    #+#             */
/*   Updated: 2024/07/10 17:42:31 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	is_sorted(t_stack *stack)
{
	int	aux;

	aux = stack->index;
	while (stack)
	{
		if (stack->index >= aux)
			aux = stack->index;
		else
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	set_index(int num, int index, t_stack **stack_a)
{
	t_stack	*temp;

	temp = *stack_a;
	while (temp)
	{
		if (temp->num == num)
		{
			temp->index = index;
			return ;
		}
		temp = temp->next;
	}
}

void	create_index(int argc, char **argv, t_stack **stack_a)
{
	int	i;
	int	j;
	int	index;
	int	num;
	int	num_aux;

	i = 1;
	while (i <= (argc))
	{
		num = ft_atoi(argv[i]);
		j = 1;
		index = 0;
		while (j <= (argc))
		{
			num_aux = ft_atoi(argv[j]);
			if (num_aux < num)
				index++;
			j++;
		}
		set_index(num, index, stack_a);
		i++;
	}
}
