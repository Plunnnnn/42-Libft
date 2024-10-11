/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:28:20 by bdenfir           #+#    #+#             */
/*   Updated: 2024/10/09 17:01:50 by bdenfir          ###   ########.fr       */
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

//
// 0 = 0000
// 1 = 0001
// 2 = 0010
// 3 = 0011
// 4 = 0100
//
//
//