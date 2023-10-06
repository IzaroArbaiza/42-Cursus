/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:08:40 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/02/02 13:20:16 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_p(char *a)
{
	int	len;

	len = 2;
	write(1, "0x", 2);
	len += ft_printf_hex((unsigned long)a, 0);
	return (len);
}
