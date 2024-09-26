/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:13:28 by bdenfir           #+#    #+#             */
/*   Updated: 2024/09/26 20:00:15 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned int	i;

	str = (unsigned char *)s;
	i = 0;
	while (i <= n && str)
	{
		if (*str == c)
			return (str);
		str++;
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <stddef.h>
int main(){

	char	str[] = "Eu vou encontrar um ponto . Ca esta ele!";
	char	c = '.';
	printf("%p", ft_memchr(&str, c, 40));
}
*/