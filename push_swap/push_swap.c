/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:11:36 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/10/04 19:33:05 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char	**argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (0);
	else if (*argv[1] == ' ' || (ft_strlen(argv[1]) == 0))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	else if (argc >= 2)
	{
		check_args(argc, argv);
		stack_a = (t_list **)malloc(sizeof(t_list *));
		stack_b = (t_list **)malloc(sizeof(t_list *));
		*stack_a = NULL;
		*stack_b = NULL;
		initialise(stack_a, argc, argv);
		if (!check_if_ordered(stack_a))
			order(stack_a, stack_b);
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
}
