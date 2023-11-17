/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 22:54:17 by junmlee           #+#    #+#             */
/*   Updated: 2023/11/17 23:11:59 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	arr_putnbr(char *arr, unsigned int nb, int *len, const char *base)
{
	long long	temp;

	if (nb >= 16)
		arr_putnbr(arr, nb / 16, len, base);
	temp = nb;
	while (temp >= 16)
	{
		temp /= 16;
		(*len)++;
	}
	*(arr + (*len)) = *(base + (nb % 16));
}

char	*ft_itoa_hex(unsigned int nb, int *len, const char *base)
{
	char	*ret;

	len = 0;
	ret = (char *)malloc(sizeof(char) * 10);
	if (ret == NULL)
		return (NULL);
	arr_putnbr(ret, nb, len, base);
	return (ret);
}
