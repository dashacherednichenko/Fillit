#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/26 15:28:53 by dpiven            #+#    #+#              #
#    Updated: 2018/12/07 16:04:47 by dpiven           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
OBJS = *.o
SRC = *.c

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@gcc -c $(CFLAGS) $(SRC)
	@ar rc $(NAME) $(OBJS)
	@gcc -o fillit main.c $(NAME) $(CFLAGS) -I libft/includes -L libft/ -lft

clean:
	@rm -f $(OBJS)
	@rm -f libft/$(OBJS)
	@rm -f *.c~
	@rm -f *~

fclean: clean
	@rm -f $(NAME)

re: fclean all

