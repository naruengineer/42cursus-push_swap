# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nando <nando@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 21:17:18 by nando             #+#    #+#              #
#    Updated: 2025/03/20 12:28:29 by nando            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
DEBUG = push_swap_debugs

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT   = libft/libft.a

SRCS = Debugs/push_swap_debugs.c \
		operations/push_swap_pushes.c \
		operations/push_swap_reverse_rotates.c \
		operations/push_swap_rotates.c \
		operations/push_swap_swaps.c \
		sorts/few_args.c \
		sorts/big_args.c \
		sorts/sort_utils.c \
		sorts/get.c \
		utils/free.c \
		utils/parse_input.c \
		utils/push_swap_atoi.c \
		utils/push_swap_stack.c \
		main/main.c

DEBUG_SRCS = \
		Debugs/push_swap_debugs.c \
		operations/push_swap_pushes.c \
		operations/push_swap_reverse_rotates.c \
		operations/push_swap_rotates.c \
		operations/push_swap_swaps.c \
		sorts/few_args.c \
		sorts/big_args.c \
		sorts/sort_utils.c \
		sorts/get.c \
		utils/free.c \
		utils/parse_input.c \
		utils/push_swap_atoi.c \
		utils/push_swap_stack.c \
		main/main.c
		

OBJS        = $(SRCS:.c=.o)
DEBUG_OBJS  = $(DEBUG_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft

debug: $(DEBUG_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(DEBUG_OBJS) $(LIBFT) -o $(DEBUG)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(DEBUG_OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME) $(DEBUG)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re debug
