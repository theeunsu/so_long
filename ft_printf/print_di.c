/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:07:00 by eahn              #+#    #+#             */
/*   Updated: 2024/04/04 11:33:40 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_di(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (print_s("-2147483648"));
	if (n < 0)
	{
		print_c('-');
		return (print_di(-n) + 1);
	}
	else if (n < 10)
		return (print_c(n + '0'));
	else
	{
		count = print_di(n / 10);
		return (count + print_di(n % 10));
	}
	return (count);
}
