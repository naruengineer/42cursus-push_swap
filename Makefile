# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nando <nando@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 21:17:18 by nando             #+#    #+#              #
#    Updated: 2025/04/18 18:06:49 by nando            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT   = libft/libft.a

SRCS =  operations/push_swap_pushes.c \
		operations/push_swap_reverse_rotates.c \
		operations/push_swap_rotates.c \
		operations/push_swap_swaps.c \
		sorts/few_args.c \
		sorts/big_args.c \
		sorts/sort_utils.c \
		utils/free_and_error.c \
		utils/parse_input.c \
		utils/push_swap_atoi.c \
		utils/stack_utils.c \
		main/main.c
		

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) 
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME) 
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
