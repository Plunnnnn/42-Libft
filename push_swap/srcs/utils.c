/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:22:29 by bdenfir           #+#    #+#             */
/*   Updated: 2024/10/08 18:56:59 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *create_node(int content)
{
	t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return NULL;
	new_node->content = content;
	new_node->stack = "A";
	new_node->next = NULL;
	new_node->previous = NULL;
	return (new_node);
}

int	ft_isdigit(int str)
{
	if (str >= '0' && str <= '9')
		return (2048);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	min;
	int	rslt;

	i = 0;
	min = 1;
	rslt = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			min = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		rslt *= 10;
		rslt += str[i++] - '0';
	}
	return (rslt * min);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n < 1)
	{
		return (0);
	}
	while ((*s1 == *s2 && *s1 && *s2) && i < n - 1)
	{
		s1++;
		s2++;
		i++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}