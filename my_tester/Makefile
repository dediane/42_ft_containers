# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 23:23:45 by ddecourt          #+#    #+#              #
#    Updated: 2022/11/21 19:16:09 by ddecourt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifneq (,$(findstring xterm,${TERM}))
	GREEN        := $(shell tput -Txterm setaf 2)
	RESET := $(shell tput -Txterm sgr0)
else
	GREEN        := ""
	RESET        := ""
endif

NAME =	ft_containers_tester

CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address -std=c++98

SRCS =	srcs/main.cpp \
		srcs/vector_tester.cpp \
		srcs/map_tester.cpp \
		srcs/stack_tester.cpp \

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
	@echo "$(GREEN)\nTester Compilation done - to start the tester run:\n $(RESET)./ft_containers_tester <container>\n\n$(GREEN) To run all containers \n$(RESET)./ft_containers_tester all"

fclean		: clean
	$(RM) $(NAME)

clean		:
	$(RM) $(OBJS)

re			:	fclean all
