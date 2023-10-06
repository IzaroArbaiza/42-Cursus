/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:35:30 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/02/01 14:17:23 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_u(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb >= 10)
	{
		i += ft_printf_u (nb / 10);
		i += ft_printf_u (nb % 10);
	}
	else if (nb >= 0)
		i += ft_printf_c (nb + 48);
	return (i);
}
