/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:07:29 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/11/09 12:50:05 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_list	lst;

	if (argc == 5 || argc == 6)
	{
		if (get_args(&lst, argc, argv) == 1)
			return (1);
	}
	else
	{
		printf("Invalid amount of arguments\n");
		return (1);
	}
	init_philo(&lst);
	if (lst.num_philo > 1 && lst.num_meals == 0)
		check_dead(&lst);
	else if (lst.num_philo > 1 && lst.num_meals > 0)
		check_dead_meals(&lst);
	join_threads(&lst);
	free_everything(&lst);
	return (0);
}
