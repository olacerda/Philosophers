#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/27 22:09:06 by otlacerd          #+#    #+#              #
#    Updated: 2026/04/04 11:50:30 by olacerda         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = philosophers

CC = cc
GCC = gcc
CFLAGS = -Wall -Wextra -Werror
GFLAGS = -Wall -Wextra -Werror -g3 -O0
RM = rm -rf
OBJ_DIR = build
INCLUDES = -I. -I./includes
VALGRIND = valgrind \
			--leak-check=full \
			--track-fds=yes \
			--show-leak-kinds=all \
			--track-origins=yes \
CHILDREN = --child-silent-after-fork=no \
			--trace-children=yes

all: $(NAME)

SRCS =	philosophers.c \
		src/execution/core_execution.c \
		src/execution/resource_management.c \
		src/execution/philo_actions.c \
		src/execution/safex_actions.c \
		src/execution/safex_utils.c \
		src/parsing/parse.c \
		src/parsing/data_structure.c \
		src/utils/print.c \
		src/utils/conversor.c \
		src/utils/data.c \
		src/utils/string.c \

OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:	
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

val: $(NAME)
	$(VALGRIND) ./$(NAME)

valchild: $(NAME)
	$(VALGRIND) $(CHILDREN) ./$(NAME)

re3:
	$(MAKE) fclean
	$(MAKE) CC=$(GCC) CFLAGS="$(GFLAGS)"
	$(VALGRIND) ./$(NAME)

val3:
	$(MAKE) CC=$(GCC) CFLAGS="$(GFLAGS)"
	$(VALGRIND) ./$(NAME)

.PHONY: all clean fclean re val valchild
