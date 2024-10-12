/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:50:37 by bdenfir           #+#    #+#             */
/*   Updated: 2024/10/12 19:41:40 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_unique(int *arr, int size, int *unique)
{
	int	i;

	i = 0;
	while (i < size)
	{
		unique[i] = arr[i];
		i++;
	}
	return (i);
}

void	sort_unique(int *unique, int uni_c)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < uni_c - 1)
	{
		j = 0;
		while (j < uni_c - i - 1)
		{
			if (unique[j] > unique[j + 1])
			{
				temp = unique[j];
				unique[j] = unique[j + 1];
				unique[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	map_comp(int *arr, int size, int *unique, int *comp)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] == unique[j])
			{
				comp[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

// Function to perform coordinate compression
int	coordinate_compression(int *arr, int size, int *comp)
{
	int	*unique;
	int	size_array;

	unique = (int *)malloc(size * sizeof(int));
	if (!unique)
		return (0);
	size_array = fill_unique(arr, size, unique);
	sort_unique(unique, size);
	map_comp(arr, size, unique, comp);
	free(unique);
	return (size_array);
}

// int main(void)
// {
// 	int arr[] = {-1, 2, 1, -5, 4, 3};
// 	int size = sizeof(arr) / sizeof(arr[0]);
// 	int *comp = (int *)malloc(size * sizeof(int));
// 	if (!comp)
// 		return 1; 
// 	coordinate_compression(arr, size, comp);
// 	printf("Original Array: ");
// 	int i = 0;
// 	while (i < size)
// 	{
// 		printf("%d ", arr[i]);
// 		i++;
// 	}
// 	printf("\ncomp Array: ");
// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("%d ", comp[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	free(comp);
// 	return 0;
// }