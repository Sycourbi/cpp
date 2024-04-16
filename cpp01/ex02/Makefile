# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 17:21:55 by sycourbi          #+#    #+#              #
#    Updated: 2024/01/25 14:32:27 by sycourbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ptr_ref

SRC = main.cpp \

OBJ = $(SRC:.cpp=.o)

CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98
#-g3

all:$(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAG) -o $(NAME) $(OBJ) -I.
# -o sert a creer le fichier executable
# -I. sert a inclure les header (.hpp)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re