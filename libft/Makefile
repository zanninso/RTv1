#
#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/08 15:15:18 by anabaoui          #+#    #+#              #
#    Updated: 2018/10/20 16:37:20 by anabaoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_lstmap.c ft_putstr_fd.c ft_strncmp.c \
	ft_lstnew.c ft_strcat.c ft_strncpy.c \
	first_spaces.c ft_memalloc.c ft_strchr.c \
	ft_strnequ.c ft_atoi.c ft_memccpy.c \
	ft_strclr.c ft_strnew.c ft_bzero.c \
	ft_memchr.c ft_strcmp.c ft_strnstr.c \
	ft_count_chars.c ft_memcmp.c ft_strcpy.c \
	ft_strrchr.c ft_count_words.c ft_memcpy.c \
	ft_strdel.c ft_strsplit.c ft_isalnum.c \
	ft_memdel.c ft_strdup.c ft_strstr.c \
	ft_isalpha.c ft_memmove.c ft_strequ.c \
	ft_strsub.c ft_isascii.c ft_memset.c \
	ft_striter.c ft_strtrim.c ft_isdigit.c \
	ft_putchar.c ft_striteri.c ft_tolower.c \
	ft_isprint.c ft_putchar_fd.c ft_strjoin.c \
	ft_toupper.c ft_itoa.c ft_putendl.c \
	ft_strlcat.c last_spaces.c ft_lstadd.c \
	ft_putendl_fd.c ft_strlen.c ft_lstdel.c \
	ft_putnbr.c ft_strmap.c nbr_len.c \
	ft_lstdelone.c ft_putnbr_fd.c ft_strmapi.c \
	strtolower.c ft_lstiter.c ft_putstr.c ft_strncat.c \
	nbrtoabs.c nbrpower.c get_next_line.c ft_atof.c \
	ft_str_to_dbl.c ft_sign.c ft_is_number.c ft_strmequ.c ft_skip_chars.c 

OBJ = $(SRC:.c=.o)

CC = gcc -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o : %.c
	@$(CC) -c $< -o $@
	@echo "Libft   : $< \033[1;32mDone\033[0m"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
