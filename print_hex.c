/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:56:43 by junmlee           #+#    #+#             */
/*   Updated: 2023/11/17 23:20:35 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_hex(unsigned int n, int *len, int *error)
{
	const char	*base = "0123456789abcdef";
	ssize_t		ret_write;

	if (n >= 16)
		put_hex(n / 16, len, error);
	ret_write = write(1, base + (n % 16), 1);
	if (ret_write == -1)
		*error = 1;
	else
		(*len) += ret_write;
}

int	print_hex(va_list *ap)
{
	unsigned int	n;
	int				len;
	int				error;

	error = 0;
	len = 0;
	n = va_arg(*ap, unsigned int);
	put_hex(n, &len, &error);
	if (error == 1)
		return (-1);
	else
		return (len);
}

int	print_hex_upper(va_list *ap)
{
	unsigned int	n;
	char			*arr;
	int				len;
	const char		*base = "0123456789ABCDEF";

	len = 0;
	n = va_arg(*ap, unsigned int);
	if (n == 0)
		arr = ft_strdup("0");
	else
		arr = ft_itoa_hex(n, &len, base);
	if (arr == NULL)
		return (-1);
	if (write(1, arr, len) == -1)
	{
		free(arr);
		return (-1);
	}
	else
	{
		free(arr);
		return (len);
	}
}
