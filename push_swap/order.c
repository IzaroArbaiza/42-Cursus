/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:13:28 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/10/03 10:17:29 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_num(t_list	**stack)
{
	t_list	*lst;
	int		min;

	lst = *stack;
	min = lst->index;
	while (lst)
	{
		if (min > lst->index)
			min = lst->index;
		lst = lst->next;
	}
	return (min);
}

void	order_3_num(t_list	**stack_a)
{
	t_list	*lst;

	lst = *stack_a;
	while (!check_if_ordered(stack_a))
	{
		if ((lst->data > lst->next->next->data)
			&& (lst->next->data < lst->next->next->data))
			ft_ra(stack_a);
		else if ((lst->next->next->data > lst->data)
			&& (lst->data > lst->next->data))
			ft_sa(stack_a);
		else
			ft_rra(stack_a);
		lst = *stack_a;
	}
}

void	order_4_5_num(t_list	**stack_a, t_list	**stack_b)
{
	t_list	*lst;
	int		min;

	lst = *stack_a;
	while (!check_if_ordered(stack_a))
	{
		lst = *stack_a;
		min = min_num(stack_a);
		if (lst->index == min)
		{
			ft_pb(stack_a, stack_b);
			if (ft_lstsize(*stack_a) == 3)
				break ;
		}
		else if (lst->next->data == min)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
	if (!check_if_ordered(stack_a))
		order_3_num(stack_a);
	while (*stack_b)
		ft_pa(stack_a, stack_b);
}

void	order(t_list	**stack_a, t_list	**stack_b)
{
	int	len;

	len = ft_lstsize(*stack_a);
	if (len > 5)
		order_radix(stack_a, stack_b);
	else
	{
		if (len == 2)
			ft_sa(stack_a);
		else if (len == 3)
			order_3_num(stack_a);
		else if (len == 4 || len == 5)
			order_4_5_num(stack_a, stack_b);
	}
}
