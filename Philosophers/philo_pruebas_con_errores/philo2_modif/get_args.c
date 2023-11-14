/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:00:50 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/11/13 12:14:26 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_meals(t_list *lst, int num)
{
	int	i;

	i = 0;
	while (i < lst->num_philo)
	{
		lst->p[i].meal = num;
		i++;
	}
	lst->num_meals = lst->num_philo * num;
}

int	get_args(t_list *lst, int argc, char **argv)
{
	int	i;

	i = 0;
	if (check(argc, argv) == 1)
		return (1);
	lst->num_philo = ft_atoi(argv[1]);
	while (i < lst->num_philo)
	{
		lst->time_die = ft_atoi(argv[2]);
		lst->time_eat = ft_atoi(argv[3]);
		lst->time_sleep = ft_atoi(argv[4]);
		i++;
	}
	lst->dead = 0;
	if (init_mutex(lst) == 1)
		return (1);
	if (init_philo(lst) == 1)
		return (1);
	if (argc == 6)
		get_meals(lst, ft_atoi(argv[5]));
	return (0);
}
