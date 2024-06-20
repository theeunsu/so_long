/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 22:50:56 by eahn              #+#    #+#             */
/*   Updated: 2024/04/05 11:12:35 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x(unsigned long n, char specifier)
{
	int		count;
	char	*symbols_low;
	char	*symbols_up;

	symbols_low = "0123456789abcdef";
	symbols_up = "0123456789ABCDEF";
	if (n < 16)
	{
		if (specifier == 'X')
			return (print_c(symbols_up[n]));
		else
			return (print_c(symbols_low[n]));
	}
	else
	{
		count = print_x(n / 16, specifier);
		return (count + print_x(n % 16, specifier));
	}
	return (count);
}
