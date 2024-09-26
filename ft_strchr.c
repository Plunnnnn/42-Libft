/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:13:41 by bdenfir           #+#    #+#             */
/*   Updated: 2024/09/26 19:49:29 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (0);
}
/*
#include <stdio.h>
int main(){

	char	str[] = "Eu vou encontrar um ponto . Ca esta ele!";
	char	c = '.';
	printf("%s", ft_strchr(str, c));
}
*/