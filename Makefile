# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 23:23:45 by ddecourt          #+#    #+#              #
#    Updated: 2022/05/15 12:05:35 by ddecourt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	containers

SRCS =	srcs/main.cpp \

CC	=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
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