/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:56:43 by junmlee           #+#    #+#             */
/*   Updated: 2023/11/17 16:20:54 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_hex(unsigned int n, int *len)
{
	const char	*base = "0123456789abcdef";

	if (n >= 16)
		put_hex(n / 16, len);
	(*len) += write(1, base + (n % 16), 1);
}

int	print_hex(va_list *ap)
{
	unsigned int	n;
	int				len;

	len = 0;
	n = va_arg(*ap, unsigned int);
	put_hex(n, &len);
	return (len);
}

void	put_hex_upper(unsigned int n, int *len)
{
	const char	*base = "0123456789ABCDEF";

	if (n >= 16)
		put_hex_upper(n / 16, len);
	(*len) += write(1, base + (n % 16), 1);
}

int	print_hex_upper(va_list *ap)
{
	unsigned int	n;
	int				len;

	len = 0;
	n = va_arg(*ap, unsigned int);
	put_hex_upper(n, &len);
	return (len);
}
