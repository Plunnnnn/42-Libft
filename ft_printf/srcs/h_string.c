/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:16:31 by bdenfir           #+#    #+#             */
/*   Updated: 2024/09/29 22:18:00 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_print.h"

int	handle_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	handle_char(int c)
{
	if (ft_isprint(c))
		return (0);
	write(1, &c, 1);
	return (1);
}
