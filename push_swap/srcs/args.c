/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:19:05 by bdenfir           #+#    #+#             */
/*   Updated: 2024/10/08 21:42:57 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_bottom(t_stack **stack, int value)
{
	t_stack *new_node = create_node(value);
	if (!*stack)
	{
		*stack = new_node;
		return;
	}

	t_stack *temp = *stack;
	while (temp->next)
		temp = temp->next;

	temp->next = new_node;
	new_node->previous = temp;
}

void print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d ", stack->content);
		stack = stack->next;
	}
	printf("\n");
}

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

void parse_and_compress(int argc, char **argv, t_stack **stack)
{
    int	*arr;
    int	*compressed;
    int	i;

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
	duplicate(arr, argc-1);
    coordinate_compression(arr, argc - 1, compressed);
    i = 0;
    while (i < argc - 1)
    {
        append_bottom(stack, compressed[i]);
        i++;
    }
    free(arr);
    free(compressed);
}

int	main(int argc, char **argv)
{
    t_stack *stack_a;  // Initialize stack A
    t_stack *stack_b;  // Initialize stack B

    stack_a = NULL;
    stack_b = NULL;
	
	if (argc < 2)
		exit(EXIT_FAILURE);
    parse_and_compress(argc, argv, &stack_a);
    print_stack(stack_a);
	binary_radix_sort(&stack_a, &stack_b, 10);
	print_stack(stack_a);
    return (0);
}