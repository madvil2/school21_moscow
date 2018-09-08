# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/08 09:19:59 by pcollio-          #+#    #+#              #
#    Updated: 2018/09/08 09:20:41 by pcollio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr

SRCS = src/main.c
INCL = includes/
OBJ = 

all: $(NAME)

$(NAME):
		gcc -Wall -Werror -Wextra -o $(NAME) -I $(INCL) $(SRCS)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re