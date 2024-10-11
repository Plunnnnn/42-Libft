/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:50:37 by bdenfir           #+#    #+#             */
/*   Updated: 2024/10/11 18:34:48 by bdenfir          ###   ########.fr       */
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

void	sort_unique(int *unique, int unique_count)
{
	int	i;
	int	j;
	int	temp;

	i=0;
	while (i < unique_count - 1)
	{
		j = 0;
		while (j < unique_count - i - 1)
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

void	map_compressed(int *arr, int size, int *unique, int unique_count, int *compressed)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < unique_count)
		{
			if (arr[i] == unique[j])
			{
				compressed[i] = j;
				break;
			}
			j++;
		}
		i++;
	}
}

// Function to perform coordinate compression
int	coordinate_compression(int *arr, int size, int *compressed)
{
	int *unique;
	int	size_array;
	
	unique = (int *)malloc(size * sizeof(int));
	if (!unique)
		return 0;
	size_array = fill_unique(arr, size, unique);
	sort_unique(unique, size);
	map_compressed(arr, size, unique, size, compressed);
	free(unique);
	return (size_array);
}

// int main(void)
// {
// 	int arr[] = {-1, 2, 1, -5, 4, 3};
// 	int size = sizeof(arr) / sizeof(arr[0]);
// 	int *compressed = (int *)malloc(size * sizeof(int));

// 	if (!compressed)
// 		return 1; 

// 	coordinate_compression(arr, size, compressed);

// 	printf("Original Array: ");
// 	int i = 0;
// 	while (i < size)
// 	{
// 		printf("%d ", arr[i]);
// 		i++;
// 	}
// 	printf("\nCompressed Array: ");
// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("%d ", compressed[i]);
// 		i++;
// 	}
// 	printf("\n");

// 	free(compressed);
// 	return 0;
// }