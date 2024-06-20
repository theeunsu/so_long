/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:05:59 by eahn              #+#    #+#             */
/*   Updated: 2024/04/04 13:36:03 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(uintptr_t ptr)
{
	int	count;

	count = 0;
	count = print_s("0x");
	if (ptr == 0)
		count += print_c('0');
	else
		count += convert_hex(ptr);
	return (count);
}

int	convert_hex(uintptr_t n)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 16)
		return (print_c(symbols[n]));
	else
	{
		count = convert_hex(n / 16);
		return (count + convert_hex(n % 16));
	}
	return (count);
}
