# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danierod <danierod@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 16:26:20 by danierod          #+#    #+#              #
#    Updated: 2022/11/24 15:37:18 by danierod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract_ol

SRC_PATH = src/
OBJECTS_NAME = $(SRC_NAME:.c=.o)
CC = cc

RM = rm -rf
SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:.c=.o)

LDLIBS = -g -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm #-fsanitize=address

%.o:		%.c
			$(CC) $(LDLIBS) -c $^ -o $@

all: $(NAME)
	
%.o: %.c
	@$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJECTS)
	-@$(CC) $(OBJECTS) $(LDLIBS) -o $(NAME)
	
clean:
	@$(RM) $(OBJECTS)

fclean:	clean
	@$(RM) $(NAME)

re: fclean all
	clear

.PHONY: all clean fclean re