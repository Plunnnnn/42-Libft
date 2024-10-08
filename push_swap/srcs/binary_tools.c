/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:28:20 by bdenfir           #+#    #+#             */
/*   Updated: 2024/10/08 16:08:17 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bit_length(unsigned int n)
{
	int length;
	
	length = 0;
	while (n > 0)
	{
		n >>= 1;
		length++;
	}
	return (length);
}

int	get_bit(int num, int bit_pos)
{
	return ((num >> bit_pos) & 1);
}
