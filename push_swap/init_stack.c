/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:31:58 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/10/04 12:15:28 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_min(t_list	**stack)
{
	t_list	*tmp;
	t_list	*min;
	int		i;

	i = 0;
	tmp = *stack;
	min = NULL;
	if (!tmp)
		return (NULL);
	while (tmp)
	{
		if ((tmp->index == -1) && (i == 0 || tmp->data < min->data))
		{
			i = 1;
			min = tmp;
		}
		tmp = tmp->next;
	}
	return (min);
}

static void	index_stack(t_list	**stack)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = get_min(stack);
	while (tmp)
	{
		tmp->index = i;
		tmp = get_min(stack);
		i++;
	}
}

void	initialise(t_list	**stack, int argc, char	**argv)
{
	t_list	*lst;
	int		i;
	char	**num;

	i = 0;
	if (argc == 2)
		num = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		num = argv;
	}
	while (num[i])
	{
		lst = ft_lstnew(ft_atoi(num[i]));
		ft_lstadd_back(stack, lst);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		free_str(num);
}
