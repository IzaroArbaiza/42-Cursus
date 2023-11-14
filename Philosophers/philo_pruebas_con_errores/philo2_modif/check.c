/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:01:39 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/11/13 12:08:04 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < (argc - 1))
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("All arguments must be numbers\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc - 1)
	{
		if (ft_atoi(argv[i]) > INT_MAX)
		{
			printf("Numbers can't be bigger than MAX\n");
			return (1);
		}
		if (ft_atoi(argv[i]) < 0)
		{
			printf("Numbers can't be negative\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check(int argc, char **argv)
{
	if (check_digit(argc, argv) == 1 || check_args(argc, argv) == 1)
		return (1);
	return (0);
}
