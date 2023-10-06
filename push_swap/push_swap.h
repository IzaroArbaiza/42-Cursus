/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:08:22 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/10/03 10:03:18 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct t_list
{
	int				data;
	int				index;
	struct t_list	*next;
}	t_list;

/* Libft */
int		ft_strlen(char	*str);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
long	ft_atoi(const char *str);
t_list	*ft_lstnew(int data);
int		ft_lstsize(t_list	*lst);
void	ft_lstadd_back(t_list **first, t_list *last);

/* Initialize */
void	initialise(t_list	**stack, int argc, char	**argv);

/* Swap */
void	ft_sa(t_list **stack_a);
void	ft_sb(t_list **stack_b);
void	ft_ss(t_list **stack_a, t_list **stack_b);

/* Push */
void	ft_pa(t_list	**stack_a, t_list	**stack_b);
void	ft_pb(t_list	**stack_a, t_list	**stack_b);

/* Rotate */
void	ft_ra(t_list	**stack_a);
void	ft_rb(t_list	**stack_b);
void	ft_rr(t_list	**stack_a, t_list	**stack_b);

/* Reverse Rotate */
void	ft_rra(t_list	**stack_a);
void	ft_rrb(t_list	**stack_b);
void	ft_rrr(t_list	**stack_a, t_list	**stack_b);

/* Order */
void	order(t_list	**stack_a, t_list	**stack_b);
void	order_3_num(t_list	**stack);
void	order_4_5_num(t_list	**stack_a, t_list	**stack_b);
void	order_radix(t_list	**stack_a, t_list	**stack_b);

/* Checks */
int		check_if_ordered(t_list	**stack);
void	check_args(int argc, char	**argv);
void	ft_error(char	*str);
int		repeated(int num, char	**argv, int i);
int		ft_isnum(char	*num);

/* Free */
void	free_str(char	**str);
void	free_stack(t_list	**stack);

#endif