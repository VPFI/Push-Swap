/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:35:51 by vperez-f          #+#    #+#             */
/*   Updated: 2024/03/15 20:43:47 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	print_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp_a;
	t_stack *temp_b;
	int		i;

	i = 1;
	temp_a = *stack_a;
	temp_b = *stack_b;
	while ((temp_a || temp_b))
	{
		if (temp_a)
		{
			if (temp_a->num)
				printf("A[%03d]|| %03d --- ", temp_a->index, temp_a -> num);
			temp_a = temp_a -> next;
		}
		else
			printf("A[%03d]|| \\\\\\ --- ", i);
		if (temp_b)
		{
			if (temp_b -> num)
				printf("%03d ||[%03d]B\n", temp_b -> num, temp_b->index);
			temp_b = temp_b -> next;
		}
		else
			printf("\\\\\\ ||[%03d]B\n", i);
	}
}

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

int		is_sorted(t_stack *stack)
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

void	radix_sort_b(int iterations, int i, t_stack **stack_a, t_stack **stack_b)
{
	int	count;

	count = count_stack(*stack_b);
	while (*stack_b && !is_sorted(*stack_a) && count && i <= iterations)
	{
		if ((((*stack_b)->index >> i) & 1) == 0)
			rotate_b(stack_b);
		else
			push_a(stack_a, stack_b);
		count--;
	}
	while (*stack_b && count)
	{
		push_a(stack_a, stack_b);
		count--;
	}
}

void	radix_sort_a(int amount, t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	iterations;
	int	count;

	iterations = 0;
	i = amount;
	while (i > 1)
	{
		i /= 2;
		iterations++;		
	}
	i = 0;
	while (i <= iterations)
	{
		count = count_stack(*stack_a);
		while (*stack_a && !is_sorted(*stack_a) && count)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a);
			count--;
		}
		radix_sort_b(iterations, i + 1, stack_a, stack_b);
		i++;
	}
	while (*stack_b)
		push_a(stack_a, stack_b);
}

int	is_dup(char* num, char** argv)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (argv[i])
	{
		if (ft_atoi(num) == ft_atoi(argv[i]))
			count += 1;
		i++;
	}
	if (1 < count)
		return (1);
	return (0);
}

long long	ft_atol(const char *str)
{
	int		i;
	long long	sign;
	long long	ans;

	i = 0;
	ans = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = ans * 10 + (str[i] - '0');
		i++;
	}
	ans *= sign;
	return (ans);
}

int	is_integer(char* num)
{
	int			length;
	int			i;
	long long	res;

	i = 0;
	if (num[i] == '-')
		i++;
	while (num[i] && num[i] == '0')
		i++;
	length = ft_strlen(&num[i]);
	if (length > 11)
		return (0);
	res = ft_atol(num);
	if (res < INT_MIN || INT_MAX < res)
			return (0);
	return (1);

}

int	valid_num(char* num)
{
	int	i;

	i = 0;
	if (num[i] == '+' || num[i] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
				return (0);
		i++;
	}
	return (1);
}

int	invalid_args(int argc, char** argv)
{
	int	i;

	i = 1;
	while (argv[i] && i < argc)
	{
		if (!valid_num(argv[i]) || !is_integer(argv[i]) || is_dup(argv[i], argv))
			return (1);
		i++;
	}
	return (0);
}

void	error_exit()
{
	write(STDERR_FILENO, "Error\n", 6);
	exit (1);
}

void	sort_three(t_stack **stack_a)
{
	int		first;
	int		second;
	int		third;
	t_stack	*temp;

	temp = *stack_a;
	first = temp->num;
	second = temp->next->num;
	third = temp->next->next->num;
	if (first < second && first < third)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (first > second && first < third)
		swap_a(stack_a);
	else if (first < second && first > third)
		r_rotate_a(stack_a);
	else if (second < third)
		rotate_a(stack_a);
	else if (second > third)
	{
		swap_a(stack_a);
		r_rotate_a(stack_a);
	}	
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int		count;

	count = count_stack(*stack_a);
	while (3 < count)
	{
		if ((*stack_a)->index == 0)
		{
			push_b(stack_a, stack_b);
			count--;
		}
		else
			rotate_a(stack_a);
	}
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	push_a(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int		count;

	count = count_stack((*stack_a));
	while (3 < count)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
		{
			push_b(stack_a, stack_b);
			count--;
		}
		else
			rotate_a(stack_a);
	}
	if (!is_sorted((*stack_a)))
		sort_three(stack_a);
	if (is_sorted((*stack_b)))
		rotate_b(stack_b);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
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

int main(int argc, char **argv)
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
		error_exit(1);
	fill_stack(&stack_a, argc, argv);
	create_index(amount, argv, &stack_a);
	init_sort(amount, &stack_a, &stack_b);
	//print_stacks(&stack_a, &stack_b);
	return (0);
}
