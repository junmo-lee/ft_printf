/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:39:30 by junmlee           #+#    #+#             */
/*   Updated: 2023/11/17 18:52:53 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_ptr(size_t n, int *len)
{
	const char	*base = "0123456789abcdef";

	if (n >= 16)
		put_ptr(n / 16, len);
	(*len) += write(1, base + (n % 16), 1);
}

int	print_ptr(va_list *ap)
{
	void	*n;
	int		len;

	len = 0;
	n = va_arg(*ap, void *);
	len += write(1, "0x", 2);
	put_ptr((size_t)n, &len);
	return (len);
}
