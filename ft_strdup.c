/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:16:28 by bdenfir           #+#    #+#             */
/*   Updated: 2024/09/26 19:57:11 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t				src_size;
	char				*ptr;
	int					index;

	index = 0;
	src_size = ft_strlen(src);
	ptr = (char *)malloc(sizeof(char) * (src_size + 1));
	if (!ptr)
		return (NULL);
	while (src[index])
	{
		ptr[index] = src[index];
		index++;
	}
	ptr[index] = '\0';
	return (ptr);
}
