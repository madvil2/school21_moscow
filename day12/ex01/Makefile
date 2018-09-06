# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/06 01:34:28 by pcollio-          #+#    #+#              #
#    Updated: 2018/09/06 21:12:11 by pcollio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat

SRCS = srcs/main.c
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