/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_radix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:40:03 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/10/04 16:04:00 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bit(t_list	**stack)
{
	t_list	*lst;
	int		max;
	int		bit;

	bit = 0;
	lst = *stack;
	max = lst->index;
	while (lst)
	{
		if (lst->index > max)
			max = lst->index;
		lst = lst->next;
	}
	while ((max >> bit) != 0)
		bit++;
	return (bit);
}

void	order_radix(t_list	**stack_a, t_list	**stack_b)
{
	t_list	*lst;
	int		i;
	int		j;
	int		len;
	int		bit;

	i = 0;
	lst = *stack_a;
	len = ft_lstsize(lst);
	bit = max_bit(stack_a);
	while (i < bit)
	{
		j = 0;
		while (j++ < len)
		{
			lst = *stack_a;
			if (((lst->index >> i) & 1) == 1)
				ft_ra(stack_a);
			else
				ft_pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			ft_pa(stack_a, stack_b);
		i++;
	}
}
