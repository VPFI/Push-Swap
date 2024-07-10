/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fill_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:20:05 by vperez-f          #+#    #+#             */
/*   Updated: 2024/07/10 17:21:05 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_lstclear(t_stack **lst)
{
	t_stack	*temp;

	if (lst)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			free(*lst);
			*lst = temp;
		}
	}
}

void	fill_stack(t_stack **stack, int argc, char **argv)
{
	t_stack	*node;
	int		i;

	i = 1;
	while ((argc - 1) > 0)
	{
		node = ft_stack_new(ft_atoi(argv[i]));
		node->index = (i - 1);
		ft_stackadd_back(stack, node);
		i++;
		argc--;
	}
}
