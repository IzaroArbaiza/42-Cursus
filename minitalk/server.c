/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:10:54 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/09/07 12:35:34 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

void	get_sig(int sig)
{
	static unsigned char	c = 0;
	static int				count = 0;

	if (count < 8)
	{
		if (sig == SIGUSR1)
			c |= (1 << count);
		else if (sig == SIGUSR2)
			c |= (0 << count);
		count++;
	}
	if (count == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		write(1, &c, 1);
		c = 0;
		count = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, get_sig);
	signal(SIGUSR2, get_sig);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		usleep(100);
	return (0);
}
