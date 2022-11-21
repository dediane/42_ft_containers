# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 23:23:45 by ddecourt          #+#    #+#              #
#    Updated: 2022/11/21 19:11:54 by ddecourt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifneq (,$(findstring xterm,${TERM}))
	GREEN        := $(shell tput -Txterm setaf 2)
	RESET := $(shell tput -Txterm sgr0)
else
	GREEN        := ""
	RESET        := ""
endif


NAME =	ft_containers

CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address -std=c++98

SRCS =	srcs/main.cpp \


CC	=	clang++
RM	=	rm -f

MESSAGE = Compilation ok - ready to test

INCLUDES = -I./includes

OBJS		:=	$(SRCS:.cpp=.o)

.PHONY		:	all clean fclean re

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all : $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $(NAME)
	@echo "${GREEN}Compilation OK - ready to test${RESET}"

fclean		: clean
	$(RM) $(NAME)

clean		:
	$(RM) $(OBJS)

re			:	fclean all
