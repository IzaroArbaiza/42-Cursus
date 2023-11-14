/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:24:53 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/11/08 13:46:36 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_everything(t_list *lst)
{
	int	i;

	i = 0;
	free(lst->thread);
	free(lst->p);
	while (i < lst->num_philo)
	{
		pthread_mutex_destroy(&lst->fork[i]);
		i++;
	}
	free(lst->fork);
	pthread_mutex_destroy(&lst->m_meal);
	pthread_mutex_destroy(&lst->m_printf);
	pthread_mutex_destroy(&lst->m_death);
}
