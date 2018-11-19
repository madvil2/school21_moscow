# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/12 23:39:36 by pcollio-          #+#    #+#              #
#    Updated: 2018/09/12 23:39:37 by pcollio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := bsq

CC := clang
CFLAGS := -g #-I include/ -Wall -Wextra -Werror

SRC_DIR := src/
OBJ_DIR := .obj/

FILES := all def_func main solve gnl imap_create

SRCS := $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS := $(addprefix $(OBJ_DIR), $(SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)src/
$(OBJ_DIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
fclean:	clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re