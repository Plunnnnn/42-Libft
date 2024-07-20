/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:20:55 by bdenfir           #+#    #+#             */
/*   Updated: 2024/07/01 19:02:12 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	static unsigned int	i;
	unsigned int		src_len;

	i = 0;
	src_len = 0;
	if (size == 0)
	{
		while (src[src_len] != '\0')
			src_len++;
		return (src_len);
	}

	while ((i < size - 1 && src[i] != '\0'))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
