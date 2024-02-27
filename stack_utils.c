/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:13:00 by vperez-f          #+#    #+#             */
/*   Updated: 2024/02/27 14:26:34 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int	num)
{
	t_stack	*res;

	res = (t_stack *)malloc(sizeof(t_stack));
	if (!res)
		return (NULL);
	res->num = num;
	res->next = NULL;
	return (res);
}
void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last_entry;

	if (lst)
	{
		if (*lst)
		{
			last_entry = ft_stacklast(*lst);
			last_entry->next = new;
		}
		else
			*lst = new;
	}
}
t_stack	*ft_stacklast(t_stack *lst)
{
	if (lst)
	{
		if (lst->next)
			return (ft_stacklast(lst->next));
	}
	return (lst);
}
