/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madcat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:48:01 by madcat            #+#    #+#             */
/*   Updated: 2021/10/26 22:41:27 by madcat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	str_print(const char *str)
{
	int	len;
	
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (*(str + len))
	{
		ft_putchar(*(str + len));
		len++;
	}
	return (len);
}

int	char_print(const char ch)
{
	ft_putchar(ch);
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
