/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:19:05 by bdenfir           #+#    #+#             */
/*   Updated: 2024/10/12 19:27:06 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_bottom(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*temp;

	new_node = create_node(value);
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
	new_node->previous = temp;
}

// void print_stack(t_stack *stack)
// {
// 	if (stack->previous != NULL)
// 		while (stack->previous != NULL)
// 			stack=stack->previous;
// 	while (stack)
// 	{
// 		printf("%d ", stack->content);
// 		stack = stack->next;
// 	}
// 	printf("\n");	
// }
// Function to parse argv and turn it into a stack using while loops
t_stack	*parse_argv_to_stack(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		append_bottom(&stack, ft_atoi(argv[i]));
		i++;
	}
	return (stack);
}

int	parse_and_compress(int argc, char **argv, t_stack **stack)
{
	int	*arr;
	int	*compressed;
	int	i;
	int	max;

	arr = (int *)malloc((argc - 1) * sizeof(int));
	compressed = (int *)malloc((argc - 1) * sizeof(int));
	if (!arr || !compressed)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < argc)
	{
		arr[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	duplicate(arr, argc - 1);
	max = coordinate_compression(arr, argc - 1, compressed);
	i = -1;
	while (++i < argc - 1)
		append_bottom(stack, compressed[i]);
	free(arr);
	free(compressed);
	return (max);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		max;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit(EXIT_FAILURE);
	max = parse_and_compress(argc, argv, &stack_a);
	binary_radix_sort(&stack_a, &stack_b, max);
	free_stack(&stack_a);
	return (0);
}
