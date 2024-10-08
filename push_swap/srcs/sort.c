/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:32:02 by bdenfir           #+#    #+#             */
/*   Updated: 2024/10/08 21:41:04 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition_by_bit(t_stack **a, t_stack **b, int bit_pos, int *count) {
	t_stack	*current;
	int		size;
	int		i;

	current = *a;
	size = stack_size(current);
	i = 0;
	while (i < size) {
		if (get_bit((*a)->content, bit_pos) == 0)
			push(a, b);
		else
			rotate(a);
		(*count)++;
		i++;
	}
}

// Move all elements back from stack `b` to stack `a`
void	move_back_to_a(t_stack **a, t_stack **b, int *count)
{
	while (*b != NULL)
	{
		push(b, a);
		(*count)++;
	}
}

// Main radix sort function
void	binary_radix_sort(t_stack **a, t_stack **b, int max_value)
{
	int	num_bits;
	int	count;
	int	bit_pos;
	int	size;

	num_bits = bit_length(max_value);
	count = 0;
	bit_pos = 0;

	while (bit_pos < num_bits) {
		size = stack_size(*a);
		if (size <= 6) {
			break;
		}
		partition_by_bit(a, b, bit_pos, &count);
		move_back_to_a(a, b, &count);
		bit_pos++;
	}
	printf("Total instructions: %d\n", count);
}

// Function to get the size of a stack
int stack_size(t_stack *stack)
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
