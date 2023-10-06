/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:57:15 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/02/02 12:24:37 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(va_list args, const char *ptr)
{
	if (*ptr == 'c')
		return (ft_printf_c(va_arg(args, int)));
	else if (*ptr == 's')
		return (ft_printf_s(va_arg(args, char *)));
	else if (*ptr == 'p')
		return (ft_printf_p(va_arg(args, char *)));
	else if (*ptr == 'd' || *ptr == 'i')
		return (ft_printf_d(va_arg(args, int)));
	else if (*ptr == 'u')
		return (ft_printf_u(va_arg(args, unsigned int)));
	else if (*ptr == 'x')
		return (ft_printf_hex(va_arg(args, unsigned int), 0));
	else if (*ptr == 'X')
		return (ft_printf_hex(va_arg(args, unsigned int), 1));
	else if (*ptr == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_convert(args, str + i + 1);
			i += 2;
		}
		else
		{
			len += write(1, str + i, 1);
			i++;
		}
	}
	va_end (args);
	return (len);
}
