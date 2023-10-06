/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 09:51:37 by izaro             #+#    #+#             */
/*   Updated: 2023/09/30 12:11:37 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_list	**stack)
{
	t_list	*first;
	t_list	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next->next != NULL)
		last = last->next;
	first = *stack;
	*stack = last->next;
	last->next = NULL;
	(*stack)->next = first;
}

void	ft_rra(t_list	**stack_a)
{
	reverse_rotate(stack_a);
	write (1, "rra\n", 4);
}

void	ft_rrb(t_list	**stack_b)
{
	reverse_rotate(stack_b);
	write (1, "rrb\n", 4);
}

void	ft_rrr(t_list	**stack_a, t_list	**stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write (1, "rrr\n", 4);
}
