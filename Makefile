# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 15:44:34 by paescano          #+#    #+#              #
#    Updated: 2023/10/14 12:06:41 by lromero-         ###   ########.fr        #
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
		handlers/handler_env.c handlers/handler_cmd.c inits/init_minishell.c \
		inits/init_env.c execute/builtins_env.c execute/builtins_dir.c \
		execute/builtins_e.c utils/ft_free_all.c utils/ft_strcmp.c utils/ft_strdup.c \
		utils/ft_signals_handler.c utils/ft_split.c utils/ft_substr.c \
		utils/ft_pplen.c utils/ft_add_pp.c utils/ft_itoa.c utils/ft_replace_str.c \
		utils/ft_isalnum.c utils/ft_set_prompt.c lexer/lexer.c lexer/check_quotes.c \
		lexer/check_pipes.c lexer/check_redir.c parser/parser.c parser/ft_split_pipe.c \
		parser/ft_split_normal.c parser/ft_split_redir.c parser/ft_expand_vars.c \
		parser/ft_expand_quotes.c utils/ft_atoi_long.c utils/ft_com_path.c \
		execute/builtins_export.c utils/ft_finish.c utils/ft_print_error.c \
		utils/ft_set_fds.c handlers/handler_exec.c execute/exe_cve.c \
		utils/ft_heredoc.c utils/ft_format_env.c

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