# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 13:37:51 by iarbaiza          #+#    #+#              #
#    Updated: 2023/07/03 10:40:33 by iarbaiza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

INCLUDES = so_long.h

SRCS =	main.c \
		read_map.c \
		game.c \
		textures.c \
		movements.c \
		errors_rules.c \
		flood_fill.c \
		frees.c \
		GNL/get_next_line.c \
		GNL/get_next_line_utils.c \
		utils/ft_split_sl.c \
		utils/so_long_utils.c \

OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g3

MINILIB = mini/libmlx.a

FT_PRINTF = ft_printf/libftprintf.a

all: $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS) $(MINILIB) $(FT_PRINTF)
	$(CC) $(CFLAGS) -framework OpenGL -framework AppKit $^ -o $(NAME)

$(MINILIB):
	@make -C ./mini 

$(FT_PRINTF):
	@make -C ./ft_printf

clean:
	@rm -rf $(OBJS)
	@rm -rf ./ft_printf/libftprintf.a
	@make clean -C ./mini
	@make clean -C ./ft_printf

fclean: clean
	@rm -f $(NAME) $(MINILIB) $(FT_PRINTF)

re:	fclean all

.PHONY: all clean fclean re