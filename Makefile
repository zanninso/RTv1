# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/06 03:38:58 by anabaoui          #+#    #+#              #
#    Updated: 2020/02/24 17:55:38 by aait-ihi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

SRC_PATH = srcs

SRC_NAME = main.c rtv1.c  intersection.c keys_hook.c\
			objects.c vectors1.c vectors2.c vectors3.c pixel_color.c camera.c\
			parse_file.c  parse_property.c #parsing.c save_objects.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(SRC_PATH)/,$(OBJ_NAME))

CC = gcc -Wall -Wextra -Werror -g

LIB = -L ./libft -lft -L ./miniLibX -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJ) lib_ft
	@$(CC) $(LIB) $(OBJ) -o $(NAME)

lib_ft :
	@make -C libft

$(SRC_PATH)/%.o : $(SRC_PATH)/%.c
	@$(CC) -c $< -o $@
	@echo "Rtv1 : $< \033[1;32mDone\033[0m"

clean :
	@make clean -C libft
	@rm -rf $(OBJ)

fclean : clean
	@make fclean -C libft
	@rm -rf $(NAME)

re : fclean all