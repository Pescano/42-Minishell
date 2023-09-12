# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paescano <paescano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 15:44:34 by paescano          #+#    #+#              #
#    Updated: 2023/09/12 15:58:50 by paescano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g -lreadline

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"

CFILES = main.c 

INCLUDES = include/minishell.h

OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

%.o : %.c
	@echo $(Y)Compiling [$<]...$(X)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJECTS)
	@echo $(G)Finished Compiling of [$(CFILES)]$(X)
	@echo
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo $(G)Finished Compiling of [$(NAME)]$(X)

clean:
	@rm -f $(OBJECTS)
	@echo $(R)Removed following objects: [$(OBJECTS)]$(X)

fclean: clean
	@rm -f $(NAME)
	@echo $(R)Removed following executable: [$(NAME)]$(X)

re: fclean all

norma:
	@echo $(B)Checking Norminette...$(X)
	@norminette $(CFILES) $(INCLUDES)

.PHONY: all clean fclean re norma