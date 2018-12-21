#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/26 15:28:53 by dpiven            #+#    #+#              #
#    Updated: 2018/12/21 13:49:36 by olrudenk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC = ft_calc_copy.c ft_list.c ft_solve.c ft_valid.c main.c

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

re: fclean all

