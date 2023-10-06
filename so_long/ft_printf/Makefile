# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 14:00:22 by iarbaiza          #+#    #+#              #
#    Updated: 2023/06/29 15:08:04 by iarbaiza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDES = ft_printf.h

SRCS =	ft_printf.c \
		ft_printf_c.c \
		ft_printf_s.c \
		ft_printf_p.c \
		ft_printf_d.c \
		ft_printf_u.c \
		ft_printf_hex.c \

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS) $(INCLUDES)
	ar rsc $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re