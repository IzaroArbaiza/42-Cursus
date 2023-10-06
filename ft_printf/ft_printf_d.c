/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:16:52 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/02/02 12:13:41 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_d(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
		i = ft_printf_s("-2147483648");
	else if (nb < 0)
	{
		i = write(1, "-", 1);
		i += ft_printf_d(-nb);
	}
	if (nb >= 10)
	{
		i += ft_printf_d(nb / 10);
		i += ft_printf_d(nb % 10);
	}
	else if (nb >= 0)
		i += ft_printf_c(nb + 48);
	return (i);
}
