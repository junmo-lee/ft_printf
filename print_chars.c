/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:52:20 by junmlee           #+#    #+#             */
/*   Updated: 2023/11/17 20:25:31 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list *ap)
{
	char	c;

	c = (char)va_arg(*ap, int);
	if (write(1, &c, 1) == -1)
		return (-1);
	else
		return (1);
}

int	print_string(va_list *ap)
{
	char	*str;
	int		ret;

	str = va_arg(*ap, char *);
	if (str == NULL)
		str = "(null)";
	ret = ft_strlen(str);
	if (write(1, str, ret) == -1)
		return (-1);
	else
		return (ret);
}
