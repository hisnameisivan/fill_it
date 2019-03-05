# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: waddam <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/05 20:24:44 by waddam            #+#    #+#              #
#    Updated: 2019/03/05 20:24:47 by waddam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = fil_algo.c\
		fil_map.c\
		fil_read.c\
		fil_struct_additions.c\
		fil_struct.c\
		fil_valid.c\
		main.c
SRC_PATH = src/
SRC_COMPL = $(addprefix $(SRC_PATH), $(SRC))
OBJ = $(SRC:%.c=%.o)
LIB = libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	gcc -Wall -Wextra -Werror $(OBJ) -o $(NAME) -L./libft -lft

$(OBJ):
	gcc -Wall -Wextra -Werror -c $(SRC_COMPL) -I include/

$(LIB):
	make -C ./libft/

clean:
	/bin/rm -f $(OBJ)
	make clean -C ./libft/

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C ./libft/

re: fclean all

.PHONY : all, clean, flcean, re