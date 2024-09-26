/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:13:40 by bdenfir           #+#    #+#             */
/*   Updated: 2024/09/26 19:51:30 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_separator(char c, char cc)
{
	return (c == cc);
}

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

void	copy_words(char const *str, char c, char **rez)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && is_separator(str[i], c))
			i++;
		start = i;
		while (str[i] && !is_separator(str[i], c))
			i++;
		if (i > start)
		{
			rez[j] = (char *)malloc(sizeof(char) * (i - start + 1));
			if (!rez[j])
				return ;
			ft_strncpy(rez[j], &str[start], i - start);
			rez[j][i - start] = '\0';
			j++;
		}
	}
	rez[j] = NULL;
}

char	**ft_split(char const *str, char c)
{
	char	**rez;

	if (!str || !c)
		return (NULL);
	rez = (char **)malloc(sizeof(char *) * (ft_strlen(str) + 1));
	if (!rez)
		return (NULL);
	copy_words(str, c, rez);
	rez[ft_strlen(str)] = NULL;
	return (rez);
}
