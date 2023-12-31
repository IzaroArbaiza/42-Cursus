/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:02:34 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/11/11 22:45:33 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_list *lst, int num)
{
	int	i;

	lst->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	if (!lst->fork)
		return (1);
	i = 0;
	while (i < num)
	{
		pthread_mutex_init(&lst->fork[i], NULL);
		i++;
	}
	return (0);
}

int	init_mutex(t_list *lst)
{
	if (init_forks(lst, lst->num_philo) == 1)
		return (1);
	pthread_mutex_init(&lst->m_meal, NULL);
	pthread_mutex_init(&lst->m_death, NULL);
	pthread_mutex_init(&lst->m_printf, NULL);
	return (0);
}

int	init_philo(t_list *lst)
{
	int	i;

	lst->p = (t_philo *)malloc(sizeof(t_philo) * lst->num_philo);
	if (!lst->p)
		return (1);
	i = 0;
	while (i < lst->num_philo)
	{
		lst->p[i].id = i + 1;
		if (lst->num_philo > 1)
			lst->p[i].l_fork = &lst->fork[(i + 1) % lst->num_philo];
		lst->p[i].r_fork = &lst->fork[i];
		lst->p[i].meal = 0;
		lst->p[i].last_meal = 0;
		lst->p[i].lst = lst;
		i++;
	}
	return (init_threads(lst));
	return (0);
}

int	init_threads(t_list *lst)
{
	int	i;

	i = 0;
	lst->thread = (pthread_t *)malloc(sizeof(pthread_t) * lst->num_philo);
	if (!lst->thread)
		return (1);
	lst->t_start = get_time();
	while (i < lst->num_philo)
	{
		if (pthread_create(&lst->thread[i], NULL, &routine, &lst->p[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	join_threads(t_list *lst)
{
	int	i;

	i = 0;
	while (i < lst->num_philo)
	{
		if (pthread_join(lst->thread[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
