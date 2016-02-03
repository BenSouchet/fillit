# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/02 12:00:30 by bsouchet          #+#    #+#              #
#    Updated: 2016/02/02 14:50:18 by bsouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME = fillit

FLAGS = -Wall -Wextra -Werror

DIR_S = sources

DIR_O = temporary

HEADER = include

SOURCES = misc.c \
		  main.c \
		  list.c \
		  error.c \
		  solve.c \
		  permute.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: temporary $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $@ $^

temporary:
	@mkdir -p temporary

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/$(NAME).h
	@$(CC) $(FLAGS) -I $(HEADER) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
