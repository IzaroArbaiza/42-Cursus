/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:00:23 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/10/04 13:24:55 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list	**stack)
{
	t_list	*a;
	t_list	*b;

	a = *stack;
	while (a)
	{
		b = a;
		a = a->next;
		free(b);
	}
	free(stack);
}

void	free_str(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}
