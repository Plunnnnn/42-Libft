/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_numbers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:14:12 by bdenfir           #+#    #+#             */
/*   Updated: 2024/09/30 15:14:25 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	handle_integer(int c)
{
	ft_putnbr_fd(c, 0);
	return (1);
}

int	handle_unsigned(unsigned int value)
{
	char	*c;
	int		length;

	c = ft_utoa(value);
	ft_putstr_fd(c, 0);
	length = (int)ft_strlen(c);
	free(c);
	return (length);
}
