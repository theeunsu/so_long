/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:09:39 by eahn              #+#    #+#             */
/*   Updated: 2024/04/04 13:36:13 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>

/* ft_printf.c */
int	print_format(char specifier, va_list ap);
int	ft_printf(const char *format, ...);

/* print_c.c */
int	print_c(int c);

/* print_s.c */
int	print_s(char *str);

/* print_p.c */
int	print_p(uintptr_t ptr);
int	convert_hex(uintptr_t n);

/* print_di.c */
int	print_di(int n);

/* print_x.c */
int	print_x(unsigned long n, char specifier);

/* print_u.c */
int	print_u(unsigned int n);
#endif
