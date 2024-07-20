/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:19:33 by bdenfir           #+#    #+#             */
/*   Updated: 2024/07/04 15:21:20 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check(char *str, char *to_find, int i)
{
	int	z;

	z = 0;
	while (to_find[z])
	{
		if (str[i + z] == to_find[z])
			z++;
		else
			return (0);
	}
	return (1);
}

char	*ft_strnstr(char *str, char *to_find, int n)
{
	int	i;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] && i <= n)
	{
		if (str[i] == to_find[0])
		{
			if (ft_check(str, to_find, i))
				return (&str[i]);
			i++;
		}
		else
			i++;
	}
	return (0);
}
