/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulee <seulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:27:08 by seulee            #+#    #+#             */
/*   Updated: 2021/10/26 23:27:10 by seulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dec_print(int number)
{
	int		ret;
	int		sign;
	short	digit[10];

	ret = 0;
	if (number == 0)
		return (char_print('0'));
	if (number < 0)
	{
		sign = -1;
		ft_putchar('-');
	}
	else
		sign = 1;
	while (number)
	{
		digit[ret] = (number % 10) * sign;
		number = number / 10;
		ret++;
	}
	num_array_print(digit, 0, ret);
	if (sign == -1)
		ret++;
	return (ret);
}

int	unsigned_dec_print(unsigned int number)
{
	int		ret;
	short	digit[10];

	if (number == 0)
	{
		ft_putchar('0');
		return (1);
	}
	ret = 0;
	while (number)
	{
		digit[ret] = (number % 10);
		number = number / 10;
		ret++;
	}
	num_array_print(digit, 0, ret);
	return (ret);
}

int	hex_print(unsigned int number, int flag)
{
	int		ret;
	short	digit[10];

	if (number == 0)
		return (char_print('0'));
	ret = 0;
	while (number)
	{
		digit[ret] = (number % 16);
		number = number / 16;
		ret++;
	}
	num_array_print(digit, flag, ret);
	return (ret);
}

int	addr_print(unsigned long addr)
{
	short	digit[16];
	int		i;

	ft_putchar('0');
	ft_putchar('x');
	if (addr == 0)
		return (char_print('0') + 2);
	i = 0;
	while (addr)
	{
		digit[i] = addr % 16;
		addr = addr / 16;
		i++;
	}
	num_array_print(digit, 1, i);
	return (i + 2);
}

void	num_array_print(short number[], int base, int digit)
{
	char	*letters[2];

	letters[0] = "0123456789ABCDEF";
	letters[1] = "0123456789abcdef";
	while (--digit >= 0)
	{
		ft_putchar(letters[base][number[digit]]);
	}
}
