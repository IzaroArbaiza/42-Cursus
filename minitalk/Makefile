# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 15:03:37 by iarbaiza          #+#    #+#              #
#    Updated: 2023/09/06 12:42:12 by iarbaiza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME = client
SERVER_NAME = server

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

FT_PRINTF = ft_printf/libftprintf.a

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_SRCS) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_SRCS) -o $(CLIENT_NAME) -Lft_printf -lftprintf

$(SERVER_NAME): $(SERVER_SRCS) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(SERVER_SRCS) -o $(SERVER_NAME) -Lft_printf -lftprintf

$(FT_PRINTF):
	@make -C ./ft_printf

clean:
	@$(RM) $(CLIENT_NAME) $(SERVER_NAME)
	@make clean -C ./ft_printf

fclean: clean
	@make fclean -C ./ft_printf

re: fclean all

.PHONY: all clean fclean re