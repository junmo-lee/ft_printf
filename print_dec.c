/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:50:34 by junmlee           #+#    #+#             */
/*   Updated: 2023/11/17 18:59:48 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_nbr(int n, int *len)
{
	const char	*base = "0123456789";

	if (n >= 10)
		put_nbr(n / 10, len);
	(*len) += write(1, base + (n % 10), 1);
}

int	print_dec(va_list *ap)
{
	int	n;
	int	len;

	len = 0;
	n = va_arg(*ap, int);
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		len += write(1, "-", 1);
		put_nbr(-n, &len);
	}
	else
		put_nbr(n, &len);
	return (len);
}

void	put_unbr(unsigned int n, int *len)
{
	const char	*base = "0123456789";

	if (n >= 10)
		put_unbr(n / 10, len);
	(*len) += write(1, base + (n % 10), 1);
}

int	print_unsigned(va_list *ap)
{
	unsigned int	n;
	int				len;

	len = 0;
	n = va_arg(*ap, unsigned int);
	put_unbr(n, &len);
	return (len);
}
