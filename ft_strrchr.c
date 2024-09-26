/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:14:06 by bdenfir           #+#    #+#             */
/*   Updated: 2024/09/26 20:46:03 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*occ;

	str = (char *)s;
	occ = NULL;
	while (*str)
	{
		if (*str == c)
			occ = str;
		str++;
	}
	return (occ);
}
