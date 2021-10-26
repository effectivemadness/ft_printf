/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulee <seulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:26:49 by seulee            #+#    #+#             */
/*   Updated: 2021/10/26 23:26:51 by seulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	ret = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ret += flag_print(ap, format);
		}
		else
			ret += char_print(*format);
		format++;
	}
	return (ret);
}

int	flag_print(va_list ap, const char *format)
{
	if (*format == 'd' || *format == 'i')
		return (dec_print(va_arg(ap, int)));
	else if (*format == 'c')
		return (char_print(va_arg(ap, int)));
	else if (*format == 'u')
		return (unsigned_dec_print(va_arg(ap, unsigned int)));
	else if (*format == 's')
		return (str_print(va_arg(ap, char *)));
	else if (*format == 'x')
		return (hex_print(va_arg(ap, unsigned int), 1));
	else if (*format == 'X')
		return (hex_print(va_arg(ap, unsigned int), 0));
	else if (*format == 'p')
		return (addr_print((unsigned long)va_arg(ap, void *)));
	else if (*format == '%')
		return (char_print('%'));
	return (-1);
}
