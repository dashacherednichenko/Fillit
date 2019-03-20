#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/26 15:28:53 by dpiven            #+#    #+#              #
#    Updated: 2019/03/20 13:45:56 by olrudenk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC = ./srcs/ft_calc_copy.c \
	  ./srcs/ft_list.c \
	  ./srcs/ft_solve.c \
	  ./srcs/ft_valid.c \
	  ./srcs/ft_fillit.c \
	  ./srcs/main.c \

LIB = @make -C libft/

all: $(NAME)

$(NAME):
	$(LIB)
	@gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) ./libft/libft.a -I./ -I./libft/

clean:
	@$(LIB) clean

fclean: clean
	@$(LIB) fclean
	@rm -f $(NAME)
	@rm -f *.c~
	@rm -f *~

re: fclean all

