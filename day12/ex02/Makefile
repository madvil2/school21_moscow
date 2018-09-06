# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/06 01:34:28 by pcollio-          #+#    #+#              #
#    Updated: 2018/09/06 23:39:34 by pcollio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail

SRCS = srcs/main.c srcs/lib.c
INCL = includes/

all: $(NAME)

$(NAME):
		gcc -Wall -Werror -Wextra -o $(NAME) -I $(INCL) $(SRCS)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
