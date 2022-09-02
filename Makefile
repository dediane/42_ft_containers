# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 23:23:45 by ddecourt          #+#    #+#              #
#    Updated: 2022/09/02 02:35:59 by ddecourt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	ft_containers

CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

SRCS =	srcs/main.cpp \
		srcs/main_vector.cpp \

CC	=	clang++
RM	=	rm -f

INCLUDES = -I./headers

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