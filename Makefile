# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 23:23:45 by ddecourt          #+#    #+#              #
#    Updated: 2022/09/02 22:46:06 by ddecourt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	ft_containers

CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address -std=c++98

SRCS =	srcs/main.cpp \

SRCS_VECTOR = tests/vector/main_vector.cpp \

CC	=	clang++
RM	=	rm -f

INCLUDES = -I./headers

OBJS		:=	$(SRCS:.cpp=.o)

OBJS_VECTOR	:=	$(SRCS_VECTOR:.cpp=.o)

.PHONY		:	all clean fclean re


%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all : $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $(NAME)

fclean		: clean
	$(RM) $(NAME)

clean		:
	$(RM) $(OBJS)

re			:	fclean all

vector:
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS_VECTOR) -o vector_test;