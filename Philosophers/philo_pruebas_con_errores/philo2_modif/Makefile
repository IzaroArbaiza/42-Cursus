# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 13:47:16 by iarbaiza          #+#    #+#              #
#    Updated: 2023/11/09 17:24:23 by iarbaiza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

INCLUDES = philo.h

SRCS =	philo.c \
		get_args.c \
		check.c \
		initialize.c \
		actions.c \
		routine.c \
		check_dead.c \
		utils.c \
		free.c \

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread -g3 -fsanitize=address

$(NAME): $(OBJS) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re