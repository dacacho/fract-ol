# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danierod <danierod@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 16:26:20 by danierod          #+#    #+#              #
#    Updated: 2022/12/02 09:52:38 by danierod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract_ol

NAME_B= fract_ol_bonus

SRC_PATH = src/

CC = cc

RM = rm -rf

SOURCES = $(wildcard src/*.c)

SOURCES_B = $(wildcard src_bonus/*bonus.c)

OBJECTS = $(SOURCES:.c=.o)

OBJECTS_B = $(SOURCES_B:.c=.o)

LDLIBS = -g -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm #-fsanitize=address

%.o:		%.c
			$(CC) $(LDLIBS) -c $^ -o $@

all: $(NAME) $(NAME_B)

m: $(NAME)

b: $(NAME_B)
	
%.o: %.c
	@$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJECTS)
	-@$(CC) $(OBJECTS) $(LDLIBS) -o $(NAME)

$(NAME_B): $(OBJECTS_B)
	-@$(CC) $(OBJECTS_B) $(LDLIBS) -o $(NAME_B)
	
clean:
	@$(RM) $(OBJECTS) $(OBJECTS_B)

fclean:	clean
	@$(RM) $(NAME) $(NAME_B)

re: fclean all
	clear

.PHONY: all clean fclean re