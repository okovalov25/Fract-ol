#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skavunen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/12 12:37:31 by skavunen          #+#    #+#              #
#    Updated: 2017/03/20 16:02:05 by okovalov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

SRC = 	fractol.c \
		color.c \
		fract.c \
		wndkey.c \

OBJ = $(SRC:.c=.o)

CC = gcc

FLGS = -Wall -Wextra -Werror

INC = ./

LIB = -L ./libft/ -lft

all: $(NAME)

$(NAME): $(OBJ)
		make -C ./libft/
		$(CC) -o $(NAME) $(OBJ) $(LIB) -lmlx -framework OpenGL -framework AppKit

%.o: %.c
		$(CC) $(FLGS) -c $<

clean:
		make -C ./libft/ clean
		rm -rf $(OBJ)

fclean: clean
		make -C ./libft/ fclean
		rm -f $(NAME)

re: fclean all