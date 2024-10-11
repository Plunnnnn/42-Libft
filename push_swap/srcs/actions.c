/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:09:37 by bdenfir           #+#    #+#             */
/*   Updated: 2024/10/11 21:37:31 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the top two elements of the stack
void	swap(t_stack **stack)
{
	t_stack	*top;
	t_stack	*second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	top = *stack;
	second = top->next;
	if (second == NULL)
		return;
	top->next = second->next;
	if (top->next != NULL)
		top->next->previous = top;
	second->next = top;
	second->previous = NULL; 
	top->previous = second;
	*stack = second;
	if (second->stack == 'A')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);

}

// Push the top elements of stack1 to the head of stack2
void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*pushed_node;

	if (*stack1 == NULL)
		return;
	pushed_node = *stack1;
	*stack1 = pushed_node->next;
	if (*stack1 != NULL)
		(*stack1)->previous = NULL;

	pushed_node->next = *stack2;
	if (*stack2 != NULL)
		(*stack2)->previous = pushed_node;
	pushed_node->previous = NULL;
	*stack2 = pushed_node;
	if (pushed_node->stack == 'A')
		write(1, "pb\n", 3);
	else
		write(1, "pa\n", 3);
	change_stack(pushed_node);
}

// Rotate stack elements (i-th elements become (i+1)-th element)
//
// Since indexing dont matter in stacks we can easily rotate 
// the stack by just putting the top elements in the prvious
// varable of the bottom elements and clearing it's next pointer
void	rotate(t_stack **stack)
{
	t_stack *node;
	t_stack *start;

	node = *stack;
	if (node == NULL || node->next == NULL)
		return;
	start = node;
	while (node->next != NULL)
		node = node->next;
	node->next = start;
	start->previous = node;
	*stack = start->next;
	(*stack)->previous = NULL;
	start->next = NULL;
	if (start->stack == 'A')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
	
}



// Reverse rotate stack elements (i-th elements become (i-1)-th element)
//
// We can apply the same idea here by sending the bottom element
// to the head of the stacks and changing it's attribute.
void	r_rotate(t_stack **stack)
{
	t_stack	*last_stack;
	t_stack	*prev_last_stack;

	if (!*stack || !(*stack)->next)
		return ;
	prev_last_stack = *stack;
	last_stack = prev_last_stack->next;
	while (last_stack->next)
	{
		prev_last_stack = last_stack;
		last_stack = last_stack->next;
	}
	prev_last_stack->next = NULL;
	last_stack->next = *stack;
	(*stack)->previous = last_stack;
	*stack = last_stack;
	write(1, "rr", 1);
	write(1, &last_stack->stack, 1);
	write(1, "\n", 1);
}

void	change_stack(t_stack *node)
{
	if (node->stack == 'A')
		node->stack = 'B';
	else
		node->stack = 'A';
}


// I will not implement rr/rrr, ss, since they are not needed for my algorithme
// but if you ever need it you can just make a function, following this pseudo
// -code
//
// def double_actions(t_stack **stack1, t_stack2 **stack2, char action)
//		if action == "rr":
//			rotate(stack1)
//			rotate(stack2)
//		elif action == "rrr":
//			r_rotate(stack1)
//			r_rotate(stack2)
//		elif action == "ss":
//			swap(stack1)
//			swap(stack2)