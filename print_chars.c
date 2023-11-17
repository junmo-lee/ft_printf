/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:52:20 by junmlee           #+#    #+#             */
/*   Updated: 2023/11/17 16:03:33 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list *ap)
{
	char	c;

	c = (char)va_arg(*ap, int);
	write(1, &c, 1);
	return (1);
}

int	print_string(va_list *ap)
{
	char	*str;
	int		ret;

	str = va_arg(*ap, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ret = ft_strlen(str);
	write(1, str, ret);
	return (ret);
}
