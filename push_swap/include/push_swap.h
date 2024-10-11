/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:53:23 by bdenfir           #+#    #+#             */
/*   Updated: 2024/10/11 18:34:00 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
    int				content;
    char			stack;
    struct s_stack	*next;
    struct s_stack	*previous;
} t_stack;

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

//STACKS METHODS
void	swap(t_stack **stack);
void	push(t_stack **a, t_stack **b);
void	rotate(t_stack	**stack);
void	r_rotate(t_stack **stack);
void	change_stack(t_stack *node);
int     is_stack_sorted(t_stack *stack);

//ARGS METHODS
int	coordinate_compression(int *arr, int size, int *compressed);
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
int     stack_size(t_stack *stack);
void	partition_by_bit(t_stack **a, t_stack **b, int bit_pos);

//BINARY
int	bit_length(unsigned int n);
int	get_bit(int num, int bit_pos);

#endif