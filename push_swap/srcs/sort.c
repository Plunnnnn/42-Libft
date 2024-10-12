/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:32:02 by bdenfir           #+#    #+#             */
/*   Updated: 2024/10/12 19:30:06 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition_by_bit(t_stack **a, t_stack **b, int bit_pos)
{
	t_stack	*current;
	int		size;
	int		i;

	current = *a;
	if (current == NULL)
		return ;
	size = stack_size(current);
	i = -1;
	while (++i < size)
	{
		if (get_bit(current->content, bit_pos) == 0)
			push(a, b);
		else
			rotate(a);
		current = *a;
	}
}

// Move all elements back from stack `b` to stack `a`
void	move_back_to_a(t_stack **a, t_stack **b)
{
	while (*b != NULL)
	{
		push(b, a);
	}
}

// Main radix sort function
void	binary_radix_sort(t_stack **a, t_stack **b, int max_value)
{
	int	num_bits;
	int	bit_pos;
	int	size;

	num_bits = bit_length(max_value);
	bit_pos = 0;
	while (bit_pos < num_bits)
	{
		size = stack_size(*a);
		if (size == -1)
			break ;
		partition_by_bit(a, b, bit_pos);
		move_back_to_a(a, b);
		bit_pos++;
	}
}

int	is_stack_sorted(t_stack *stack)
{
	if (stack == NULL || stack->next == NULL)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_size(t_stack *stack)
{
	int		size;
	t_stack	*current;

	size = 0;
	current = stack;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}
