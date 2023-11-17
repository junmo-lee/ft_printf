/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:39:30 by junmlee           #+#    #+#             */
/*   Updated: 2023/11/17 21:14:52 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_ptr(size_t n, int *len, int *error)
{
	const char	*base = "0123456789abcdef";
	ssize_t		ret_write;

	if (n >= 16)
		put_ptr(n / 16, len, error);
	ret_write = write(1, base + (n % 16), 1);
	if (ret_write == -1)
		*error = 1;
	else
		(*len) += ret_write;
}

int	print_ptr(va_list *ap)
{
	void	*n;
	int		len;
	int		error;

	error = 0;
	len = 0;
	n = va_arg(*ap, void *);
	if (write(1, "0x", 2) == -1)
		return (-1);
	else
		len += 2;
	put_ptr((size_t)n, &len, &error);
	if (error == 1)
		return (-1);
	else
		return (len);
}
