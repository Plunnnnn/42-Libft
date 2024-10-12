/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integrity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:07:18 by bdenfir           #+#    #+#             */
/*   Updated: 2024/10/12 19:29:01 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplicate(int array[], int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				exit(EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_null(int array[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == 0)
			exit(EXIT_FAILURE);
		i++;
	}
	return (0);
}
