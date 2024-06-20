/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:07:23 by eahn              #+#    #+#             */
/*   Updated: 2024/04/03 21:07:30 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(unsigned int n)
{
	int	count;

	if (n < 10)
		return (print_c(n + '0'));
	else
	{
		count = print_u(n / 10);
		return (count + print_u(n % 10));
	}
	return (count);
}
