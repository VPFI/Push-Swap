/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:56:50 by vperez-f          #+#    #+#             */
/*   Updated: 2024/03/05 18:00:57 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef push_swap_H
# define push_swap_H

# include "libft/libft.h"

typedef struct s_stack
{
	int             num;
	struct s_stack	*next;
}					t_stack;

t_stack	*ft_stack_new(int num);
t_stack	*ft_stacklast(t_stack *lst);
t_stack	*ft_stackbefore_last(t_stack *lst);

void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	swap_all(t_stack **a, t_stack **b);
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rotate_all(t_stack **a, t_stack **b);
void    r_rotate_a(t_stack **a);
void    r_rotate_b(t_stack **b);
void    r_rotate_all(t_stack **a, t_stack **b);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void    first_sort(t_stack **a, t_stack **b, int argc);
void	sort(t_stack **a, t_stack **b, int argc, int prev_pivot, int side, int og_pivot, int hi, int lo);
void	sort2(t_stack **a, t_stack **b, int argc, int prev_pivot, int side, int og_pivot, int lo);
void	print_stacks(t_stack **stack_a, t_stack **stack_b);

#endif