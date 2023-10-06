# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 10:45:23 by iarbaiza          #+#    #+#              #
#    Updated: 2023/10/02 10:04:38 by iarbaiza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INCLUDES = push_swap.h

SRCS =	push_swap.c \
		init_stack.c \
		order.c \
		order_radix.c \
		operations/ope_p.c \
		operations/ope_r.c \
		operations/ope_rr.c \
		operations/ope_s.c \
		utils/ft_split.c \
		utils/list_utils.c \
		utils/utils.c \
		check.c \
		free.c \

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	rm -f

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re