# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danierod <danierod@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 16:26:20 by danierod          #+#    #+#              #
#    Updated: 2022/11/09 21:45:23 by danierod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract_ol

SRC_PATH = src/
OBJECTS_NAME = $(SRC_NAME:.c=.o)
CC = gcc

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
	@mv $(OBJECTS) objects/
	
clean:
	@$(RM) objects/*.o

fclean:	clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re