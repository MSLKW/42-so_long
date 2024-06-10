/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:35:35 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/08 10:50:17 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft.h"
# include <stdarg.h>

# define FILE_DESCRIPTOR 1
# define LONG_MAX 2147483647

int		ft_printf(const char *text, ...);
int		process_format_specifier(char f_spec, va_list ap);
void	ft_put_u_nbr_fd(unsigned int n, int fd, int *char_count);
void	ft_put_hex(unsigned long num, const char format, int *char_count);
int		count_digits(int n);

int		fspec_c(va_list ap);
int		fspec_s(va_list ap);
int		fspec_p(va_list ap);
int		fspec_d(va_list ap);
int		fspec_i(va_list ap);
int		fspec_u(va_list ap);
int		fspec_x(va_list ap, const char format);

#endif