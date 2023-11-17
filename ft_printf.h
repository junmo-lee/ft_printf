/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:44:59 by junmlee           #+#    #+#             */
/*   Updated: 2023/11/17 23:18:47 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *format, ...);
int		formatting(char type, va_list *ap);
int		print_char(va_list *ap);
int		print_string(va_list *ap);
int		print_dec(va_list *ap);
int		print_unsigned(va_list *ap);
int		print_hex(va_list *ap);
int		print_hex_upper(va_list *ap);
void	put_hex(unsigned int n, int *len, int *error);
int		print_ptr(va_list *ap);

char	*ft_uitoa(unsigned long n);
char	*ft_itoa_hex(unsigned int nb, int *len, const char *base);

#endif