/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 09:50:51 by izaro             #+#    #+#             */
/*   Updated: 2023/09/30 15:39:09 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_list	*stack_bottom(t_list	*stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

static void	rotate(t_list	**stack)
{
	t_list	*first;
	t_list	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	last = stack_bottom(*stack);
	first->next = NULL;
	last->next = first;
}

void	ft_ra(t_list	**stack_a)
{
	rotate(stack_a);
	write (1, "ra\n", 3);
}

void	ft_rb(t_list	**stack_b)
{
	rotate(stack_b);
	write (1, "rb\n", 3);
}

void	ft_rr(t_list	**stack_a, t_list	**stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write (1, "rr\n", 3);
}
