/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:23:11 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/10/04 19:34:48 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(char	*num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	repeated(int num, char	**argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	check_if_ordered(t_list	**stack)
{
	t_list	*lst;

	lst = *stack;
	while (lst->next && lst)
	{
		if (lst->data > lst->next->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	ft_error(char	*num)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(num);
	while (i < len)
	{
		write(2, &num[i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit(-1);
}

void	check_args(int argc, char **argv)
{
	int		i;
	long	num;
	char	**arg;

	i = 0;
	if (argc == 2)
		arg = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		arg = argv;
	}
	if (arg == NULL)
		ft_error("Error");
	while (arg[i])
	{
		num = ft_atoi(arg[i]);
		if (!ft_isnum(arg[i]) || (repeated(num, arg, i))
			|| (num < INT_MIN || num > INT_MAX))
			ft_error("Error");
		i++;
	}
	if (argc == 2)
		free_str(arg);
}
