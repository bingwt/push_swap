# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 19:17:02 by btan              #+#    #+#              #
#    Updated: 2024/01/26 02:42:24 by btan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INCLUDES = includes

SRCS = srcs/main.c \
		srcs/push_swap_utils.c \
		srcs/stacks.c \
		srcs/stack_utils.c \
		srcs/moves.c \
		srcs/swap.c \
		srcs/push.c \
		srcs/rotate.c \
		srcs/reverse_rotate.c \
		srcs/sort_utils.c \
		srcs/sort.c

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

MLXFLAGS = -lXext -lX11

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	make -C Libft
	mv ./Libft/libft.a ./
	make fclean -C Libft
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -I$(INCLUDES) -ILibft libft.a

clean:
	rm -rf $(OBJECTS) $(NAME).a libft.a

fclean: clean
	rm -rf $(NAME)

re: fclean all

test:
	cc test_main.c push_swap_utils.c moves.c -ILibft libft.a -g
playground:
	cc playground.c srcs/push_swap_utils.c srcs/stacks.c srcs/stack_utils.c srcs/moves.c srcs/swap.c srcs/push.c srcs/rotate.c srcs/reverse_rotate.c srcs/sort_utils.c srcs/sort.c -Iincludes -ILibft libft.a -g
