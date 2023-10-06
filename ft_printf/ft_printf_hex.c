/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:23:13 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/02/02 13:20:52 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hex(unsigned long n, int i)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_printf_hex(n / 16, i);
	n = n % 16;
	if (n < 10)
		len += ft_printf_c(n + 48);
	else if (i == 0)
		len += ft_printf_c(n + 87);
	else if (i == 1)
		len += ft_printf_c(n + 55);
	return (len);
}
