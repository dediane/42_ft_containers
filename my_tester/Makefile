# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 23:23:45 by ddecourt          #+#    #+#              #
#    Updated: 2022/11/08 17:08:42 by ddecourt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	ft_containers_tester

CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address -std=c++98

SRCS =	srcs/main.cpp \
		srcs/vector_tester.cpp \
		srcs/map_tester.cpp \


CC	=	clang++
RM	=	rm -f

INCLUDES = -I./includes

OBJS		:=	$(SRCS:.cpp=.o)

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
