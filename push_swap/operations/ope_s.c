/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 09:42:09 by izaro             #+#    #+#             */
/*   Updated: 2023/09/30 12:14:40 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	swap(t_list	*stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = tmp;
}

void	ft_sa(t_list **stack_a)
{
	swap((*stack_a));
	write (1, "sa\n", 3);
}

void	ft_sb(t_list **stack_b)
{
	swap((*stack_b));
	write (1, "sb\n", 3);
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a && *stack_b)
	{
		swap((*stack_a));
		swap((*stack_b));
		write (1, "ss\n", 3);
	}
}
