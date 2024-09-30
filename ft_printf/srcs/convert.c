/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:08:42 by bdenfir           #+#    #+#             */
/*   Updated: 2024/09/30 16:17:51 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_base(unsigned long n, const char *base)
{
	char			*str;
	int				len;
	unsigned long	tmp;

	len = 1;
	tmp = n;
	while (tmp >= ft_strlen(base))
	{
		len++;
		tmp /= ft_strlen(base);
	}
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	write(1, str, ft_strlen(str));
	len = ft_strlen(str);
	free(str);
	return (len);
}

int	handle_conversion(const char *conversion, va_list args)
{
	if (*conversion == 'd' || *conversion == 'i')
		return (handle_integer(va_arg(args, int)));
	else if (*conversion == 's')
		return (handle_string(va_arg(args, char *)));
	else if (*conversion == 'c')
		return (handle_char(va_arg(args, int)));
	else if (*conversion == 'x')
		return (handle_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (*conversion == 'X')
		return (handle_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (*conversion == 'u')
		return (handle_unsigned(va_arg(args, unsigned int)));
	else if (*conversion == 'o')
		return (handle_base(va_arg(args, unsigned int), "01234567"));
	else if (*conversion == 'p')
	{
		write(1, "0x", 2);
		return (handle_base((unsigned long)va_arg(args, void *),
				"0123456789abcdef"));
	}
	else if (*conversion == '%')
		return (handle_char('%'));
	return (0);
}
