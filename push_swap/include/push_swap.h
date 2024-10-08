/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:53:23 by bdenfir           #+#    #+#             */
/*   Updated: 2024/10/08 21:42:24 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_stack {
    char			*stack;
	int 			content;
    struct s_stack	*previous;
    struct s_stack	*next;
} t_stack;

# include <stdio.h>
# include <stdlib.h>

//stacks methods
void	swap(t_stack **stack);
void	push(t_stack **a, t_stack **b);
void	rotate(t_stack	**stack);
void	r_rotate(t_stack **stack);
void	change_stack(t_stack *node);

//ARGS METHODS
void	coordinate_compression(int *arr, int size, int *compressed);
t_stack	*parse_argv_to_stack(int argc, char **argv);

//UTILITIES
void	print_stack(t_stack *stack);
t_stack *create_node(int content);
int		ft_atoi(const char *str);
int		ft_strncmp(char *s1, char *s2, unsigned int n);

//INTEGRITY
int	duplicate(int array[], int size);
int	check_null(int array[], int size);

//SORTING
void	binary_radix_sort(t_stack **a, t_stack **b, int max_value);
int stack_size(t_stack *stack);

//BINARY
int	bit_length(unsigned int n);
int	get_bit(int num, int bit_pos);

#endif