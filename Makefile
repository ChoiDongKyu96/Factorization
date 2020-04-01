# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dochoi <dochoi@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/01 18:34:13 by dochoi            #+#    #+#              #
#    Updated: 2020/04/01 21:20:03 by dochoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = factorization
SRCS = ./factorization.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror

$(NAME):	$(SRCS)
	@$(CC) $(FLAGS) $(SRCS) -o $@
	@echo "complete\n"

all:	$(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean:	clean
	/bin/rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
