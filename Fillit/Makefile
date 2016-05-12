# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/14 12:35:48 by maxpetit          #+#    #+#              #
#    Updated: 2016/03/15 15:04:52 by maxpetit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = agencement.c check.c check_file.c create_map.c create_tetriminos.c fct_print.c main.c tetri_mvt.c initialize.c
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f nothing

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

