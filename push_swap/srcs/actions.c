/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:09:37 by bdenfir           #+#    #+#             */
/*   Updated: 2024/10/08 18:57:19 by bdenfir          ###   ########.fr       */
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
	while (top->next != NULL)
		top = top->next;
	second = top->previous;
	top->previous = second->previous;
	second->next = top->next;
	if (second->previous != NULL)
		second->previous->next = top;
	top->next = second;
	second->previous = top;
	if (top->previous == NULL)
		*stack = top;
}

// Push the top elements of stack1 to the head of stack2
void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*pushed_node;
	t_stack	*node;

	pushed_node = *stack1;
	while (pushed_node->next != NULL)
		pushed_node = pushed_node->next;
	if (pushed_node->previous != NULL)
		pushed_node->previous->next = NULL;
	else
		*stack1 = NULL;
	node = *stack2;
	if (!*stack2)
	{
		*stack2 = pushed_node;
		pushed_node->previous = NULL;
		return;
	}
	while (node->next != NULL)
		node = node->next;
	pushed_node->previous = node;
	node->next = pushed_node;
	pushed_node->next = NULL;
	change_stack(pushed_node);
}

// Rotate stack elements (i-th elements become (i+1)-th element)
//
// Since indexing dont matter in stacks we can easily rotate 
// the stack by just putting the top elements in the prvious
// varable of the bottom elements and clearing it's next pointer
void	rotate(t_stack	**stack)
{
	t_stack	*node;
	t_stack *start;

	node = *stack;
	start = *stack;
	if (node->next == NULL && node->previous == NULL)
		return ;
	while (node->next != NULL)
		node = node->next;
	while (start->previous != NULL)
		start = start->previous;
	node->next = start;
	node->previous->next = NULL;
	node->previous = NULL;
	start->previous = node;
	*stack = node;
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
		prev_last_stack = prev_last_stack->next;
		last_stack = last_stack->next;
	}
	prev_last_stack->next = NULL;
	last_stack->next = *stack;
	*stack = last_stack;
}

void change_stack(t_stack *node)
{
    if (ft_strncmp(node->stack, "A", 1) == 0)
        node->stack = "B";
    else
        node->stack = "A";
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