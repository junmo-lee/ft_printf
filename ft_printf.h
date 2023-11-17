/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:44:59 by junmlee           #+#    #+#             */
/*   Updated: 2023/11/17 18:40:47 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *format, ...);
int		type_check(char type, va_list *ap);
int		print_char(va_list *ap);
int		print_string(va_list *ap);
int		print_dec(va_list *ap);
int		print_unsigned(va_list *ap);
int		print_hex(va_list *ap);
int		print_hex_upper(va_list *ap);
void	put_hex_upper(unsigned int n, int *len);
void	put_hex(unsigned int n, int *len);
int		print_ptr(va_list *ap);

#endif