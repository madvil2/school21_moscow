# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/08 09:19:59 by pcollio-          #+#    #+#              #
#    Updated: 2018/09/09 18:36:38 by pcollio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := eval_expr

CC := clang
CFLAGS := -I include/ -Wall -Wextra -Werror

SRCS := src/def_func.c src/own_func.c src/stack_char_func.c src/stack_int_func.c src/main.c

OBJ_DIR := .obj/
OBJS := $(addprefix $(OBJ_DIR), $(SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)src/
$(OBJ_DIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
fclean:	clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
