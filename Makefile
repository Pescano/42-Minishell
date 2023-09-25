# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paescano <paescano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 15:44:34 by paescano          #+#    #+#              #
#    Updated: 2023/09/25 13:51:06 by paescano         ###   ########.fr        #
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
		execute/builtins_env.c execute/builtins_dir.c utils/ft_free_all.c \
		utils/ft_strcmp.c utils/ft_strdup.c utils/ft_signals_handler.c utils/ft_split.c \
		utils/ft_substr.c execute/builtins_e.c lexer/lexer.c lexer/check_quotes.c \
		lexer/check_pipes.c lexer/check_redir.c

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