/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:13:40 by bdenfir           #+#    #+#             */
/*   Updated: 2024/09/30 16:34:01 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static	size_t	count_words(char const *s, char c)
{
	size_t		count;
	size_t		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static	void	fill_tab(char *tab, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
}

static void	fill_rslt(char **rslt, char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		count;

	i = 0;
	j = 0;
	while (s[i])
	{
		count = 0;
		while ((s[i + count]) && s[i + count] != c)
			count++;
		if (count > 0)
		{
			rslt[j] = malloc (sizeof(char) * (count + 1));
			if (!rslt[j])
				return ;
			fill_tab(rslt[j], &s[i], c);
			j++;
			i += count;
		}
		else
			i++;
	}
	rslt[j] = 0;
	return ;
}

char	**ft_split(char const *s, char c)
{
	size_t		words;
	char		**rslt;

	words = count_words(s, c);
	rslt = malloc(sizeof(char *) * (words + 1));
	if (!rslt)
		return (0);
	fill_rslt(rslt, s, c);
	return (rslt);
}
