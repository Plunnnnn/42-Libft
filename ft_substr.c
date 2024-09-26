/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:14:11 by bdenfir           #+#    #+#             */
/*   Updated: 2024/09/26 19:58:42 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	if (len == 0)
	{
		ptr = (char *)malloc(1);
		return (ptr);
	}
	ptr = (char *)malloc(sizeof(char) * (len) + 1);
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	return (ptr);
}
