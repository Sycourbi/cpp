# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 16:08:25 by sycourbi          #+#    #+#              #
#    Updated: 2024/03/11 17:28:24 by sycourbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = span

SRC = main.cpp \
	Span.cpp \
	
OBJ = $(SRC:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
#-g3

all:$(NAME)

$(NAME): $(OBJ)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ) -I.
# -o sert a creer le fichier executable
# -I. sert a inclure les header (.hpp)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re