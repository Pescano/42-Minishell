# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paescano <paescano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 15:44:34 by paescano          #+#    #+#              #
#    Updated: 2023/09/17 19:47:36 by paescano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
FLAGS = -Wall -Werror -Wextra -g
RM = rm -rf
RL = -lreadline

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"

CFILES = main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		handlers/handler_env.c inits/init_minishell.c inits/init_env.c \
		utils/ft_free_all.c utils/ft_signals_handler.c utils/ft_split.c \
		utils/ft_strdup.c \

INCLUDES = -I ./include

OBJECTS = $(CFILES:.c=.o)

SYS	= $(shell uname -s)

ifeq ($(SYS), Darwin)
	INCLUDES +=	-I ~/.brew/opt/readline/include/
	RL	+= -L ~/.brew/opt/readline/lib
endif

%.o : %.c
	@echo $(Y)Compiling [$<]...$(X)
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(NAME): $(OBJECTS)
	@echo $(G)Finished Compiling of [$(CFILES)]$(X)
	@echo
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) -o $(NAME) $(RL)
	@echo $(G)Finished Compiling of [$(NAME)]$(X)

all: $(NAME)

clean:
	@$(RM) $(OBJECTS)
	@echo $(R)Removed following objects: [$(OBJECTS)]$(X)

fclean: clean
	@$(RM) $(NAME)
	@echo $(R)Removed following executable: [$(NAME)]$(X)

re: fclean all

norma:
	@echo $(B)Checking Norminette...$(X)
	@norminette $(CFILES) ./include

.PHONY: all clean fclean re norma