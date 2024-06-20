/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 22:42:59 by eahn              #+#    #+#             */
/*   Updated: 2024/04/05 11:17:50 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_c(va_arg(ap, int));
	else if (specifier == 's')
		count += print_s(va_arg(ap, char *));
	else if (specifier == 'p')
		count += print_p(va_arg(ap, uintptr_t));
	else if (specifier == 'd' || specifier == 'i')
		count += print_di(va_arg(ap, int));
	else if (specifier == 'x' || specifier == 'X')
		count += print_x(va_arg(ap, unsigned int), specifier);
	else if (specifier == 'u')
		count += print_u(va_arg(ap, unsigned int));
	else if (specifier == '%')
		count += print_c('%');
	return (count);
}

// int	main(void)
// {
// 	int		count;
// 	void	*ptr;
// 	int		i;

// 	i = 3;
// 	ptr = &i;

// 	count = ft_printf("%p\n", &ptr);
// 	printf("%p\n", &ptr);
// 	ft_printf("%p\n", &ptr);
// 	ft_printf("The chars written (count): %i\n", count);
// }
