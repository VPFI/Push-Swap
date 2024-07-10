/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:56:50 by vperez-f          #+#    #+#             */
/*   Updated: 2024/07/10 17:43:49 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
}					t_stack;

t_stack		*ft_stack_new(int num);
t_stack		*ft_stacklast(t_stack *lst);
t_stack		*ft_stackbefore_last(t_stack *lst);

void		push_a(t_stack **a, t_stack **b);
void		push_b(t_stack **a, t_stack **b);
void		swap_a(t_stack **a);
void		swap_b(t_stack **b);
void		swap_all(t_stack **a, t_stack **b);
void		rotate_a(t_stack **a);
void		rotate_b(t_stack **b);
void		rotate_all(t_stack **a, t_stack **b);
void		r_rotate_a(t_stack **a);
void		r_rotate_b(t_stack **b);
void		r_rotate_all(t_stack **a, t_stack **b);
void		ft_stackadd_front(t_stack **lst, t_stack *new);
void		ft_stackadd_back(t_stack **lst, t_stack *new);
void		fill_stack(t_stack **stack, int argc, char **argv);
void		stack_lstclear(t_stack **lst);
void		print_stacks(t_stack **stack_a, t_stack **stack_b);

int			count_stack(t_stack *stack);
int			is_sorted(t_stack *stack);
void		set_index(int num, int index, t_stack **stack_a);
void		create_index(int argc, char **argv, t_stack **stack_a);

void		sort_three(t_stack **stack_a);
void		sort_four(t_stack **stack_a, t_stack **stack_b);
void		sort_five(t_stack **stack_a, t_stack **stack_b);
void		radix_sort_b(int it, int i, t_stack **stack_a, t_stack **stack_b);
void		radix_sort_a(int amount, t_stack **stack_a, t_stack **stack_b);

int			is_dup(char *num, char **argv);
int			is_integer(char *num);
int			valid_num(char *num);
int			invalid_args(int argc, char **argv);
long long	ft_atol(const char *str);

#endif