/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:00:20 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/02/02 14:24:10 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_convert(va_list args, const char *ptr);
int	ft_printf_c(char c);
int	ft_printf_s(char *str);
int	ft_printf_p(char *a);
int	ft_printf_d(int nb);
int	ft_printf_u(unsigned int nb);
int	ft_printf_hex(unsigned long n, int i);

#endif