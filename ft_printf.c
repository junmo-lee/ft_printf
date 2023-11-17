/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:48:36 by junmlee           #+#    #+#             */
/*   Updated: 2023/11/17 17:24:34 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_check(char type, va_list *ap)
{
	if (type == 'c')
		return (print_char(ap));
	else if (type == 's')
		return (print_string(ap));
	else if (type == 'p')
		return (print_ptr(ap));
	else if (type == 'd' || type == 'i')
		return (print_dec(ap));
	else if (type == 'u')
		return (print_unsigned(ap));
	else if (type == 'x')
		return (print_hex(ap));
	else if (type == 'X')
		return (print_hex_upper(ap));
	else if (type == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		i;
	va_list	ap;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	len = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			len += type_check(format[i + 1], &ap);
			i++;
		}
		else
		{
			write(1, format + i, 1);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}
