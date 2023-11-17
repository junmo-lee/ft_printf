/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:50:34 by junmlee           #+#    #+#             */
/*   Updated: 2023/11/17 22:39:29 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_dec(va_list *ap)
{
	int		n;
	ssize_t	ret_write;
	char	*num_array;

	n = va_arg(*ap, int);
	num_array = ft_itoa(n);
	if (num_array == NULL)
		return (-1);
	ret_write = write(1, num_array, ft_strlen(num_array));
	free(num_array);
	num_array = NULL;
	if (ret_write == -1)
		return (-1);
	else
		return (ret_write);
}

int	print_unsigned(va_list *ap)
{
	unsigned int	n;
	ssize_t			ret_write;
	char			*num_array;

	n = va_arg(*ap, unsigned int);
	num_array = ft_uitoa(n);
	if (num_array == NULL)
		return (-1);
	ret_write = write(1, num_array, ft_strlen(num_array));
	free(num_array);
	num_array = NULL;
	if (ret_write == -1)
		return (-1);
	else
		return (ret_write);
}
