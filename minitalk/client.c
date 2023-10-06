/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:11:36 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/09/11 10:10:26 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int	g_pid = 0;

void	send_signal(int bit)
{
	if (bit)
		kill(g_pid, SIGUSR1);
	else
		kill(g_pid, SIGUSR2);
	usleep(100);
}

void	send_bit(char *sig)
{
	char	c;
	int		i;

	c = *sig;
	while (*sig)
	{
		i = 0;
		while (i < 8)
		{
			send_signal(c & (1 << i));
			i++;
		}
		sig++;
		c = *sig;
	}
	i = 0;
	while (i < 8)
	{
		kill(g_pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int	c;
	int	s;
	int	res;

	c = 0;
	s = 1;
	res = 0;
	while ((str[c] >= '\t' && str[c] <= '\r') || str[c] == ' ')
		c++;
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			s *= -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		res = (res * 10) + (str[c] - '0');
		c++;
	}
	return (res * s);
}

int	main(int argc, char *argv[])
{
	errno = 22;
	if (argc != 3)
	{
		perror("Error");
		return (1);
	}
	g_pid = ft_atoi(argv[1]);
	send_bit(argv[2]);
	return (0);
}
