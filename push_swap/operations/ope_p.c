/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 09:50:04 by izaro             #+#    #+#             */
/*   Updated: 2023/09/30 11:48:16 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	push(t_list	**a, t_list	**b)
{
	t_list	*tmp;

	if (*a == NULL)
		return ;
	tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
}

void	ft_pa(t_list	**stack_a, t_list	**stack_b)
{
	push (stack_b, stack_a);
	write (1, "pa\n", 3);
}

void	ft_pb(t_list	**stack_a, t_list	**stack_b)
{
	push (stack_a, stack_b);
	write (1, "pb\n", 3);
}
