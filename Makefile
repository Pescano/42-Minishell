# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 15:44:34 by paescano          #+#    #+#              #
#    Updated: 2023/10/30 12:55:09 by lromero-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
NAME_BONUS = minishell_bonus

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
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
		utils/ft_heredoc.c utils/ft_format_env.c utils/ft_close_p.c \

CFILES_BONUS = bonus/main_bonus.c bonus/get_next_line/get_next_line_bonus.c bonus/get_next_line/get_next_line_utils_bonus.c \
		bonus/handlers/handler_env_bonus.c bonus/handlers/handler_cmd_bonus.c bonus/inits/init_minishell_bonus.c \
		bonus/inits/init_env_bonus.c bonus/execute/builtins_env_bonus.c bonus/execute/builtins_dir_bonus.c \
		bonus/execute/builtins_e_bonus.c bonus/utils/ft_free_all_bonus.c bonus/utils/ft_strcmp_bonus.c bonus/utils/ft_strdup_bonus.c \
		bonus/utils/ft_signals_handler_bonus.c bonus/utils/ft_split_bonus.c bonus/utils/ft_substr_bonus.c \
		bonus/utils/ft_pplen_bonus.c bonus/utils/ft_add_pp_bonus.c bonus/utils/ft_itoa_bonus.c bonus/utils/ft_replace_str_bonus.c \
		bonus/utils/ft_isalnum_bonus.c bonus/utils/ft_set_prompt_bonus.c bonus/lexer/lexer_bonus.c bonus/lexer/check_quotes_bonus.c \
		bonus/lexer/check_pipes_bonus.c bonus/lexer/check_redir_bonus.c bonus/parser/parser_bonus.c bonus/parser/ft_split_pipe_bonus.c \
		bonus/parser/ft_split_normal_bonus.c bonus/parser/ft_split_redir_bonus.c bonus/parser/ft_expand_vars_bonus.c \
		bonus/parser/ft_expand_quotes_bonus.c bonus/utils/ft_atoi_long_bonus.c bonus/utils/ft_com_path_bonus.c \
		bonus/execute/builtins_export_bonus.c bonus/utils/ft_finish_bonus.c bonus/utils/ft_print_error_bonus.c \
		bonus/utils/ft_set_fds_bonus.c bonus/handlers/handler_exec_bonus.c bonus/execute/exe_cve_bonus.c \
		bonus/utils/ft_heredoc_bonus.c bonus/utils/ft_format_env_bonus.c bonus/utils/ft_close_p_bonus.c \
		bonus/utils/ft_strnstr_bonus.c bonus/utils/ft_strncmp_bonus.c bonus/ast/ft_main_ast_bonus.c \
		bonus/ast/ft_find_ast_bonus.c bonus/ast/ft_find_match_bonus.c bonus/ast/ft_split_ast_bonus.c \

INCLUDES = -I ./include

INCLUDES_BONUS = -I ./bonus/include

OBJECTS = $(CFILES:.c=.o)

OBJECTS_BONUS = $(CFILES_BONUS:.c=.o)

SYS	= $(shell uname -s)

ifeq ($(SYS), Darwin)
	INCLUDES +=	-I ~/.brew/opt/readline/include/
	INCLUDES_BONUS +=	-I ~/.brew/opt/readline/include/
	RL	+= -L ~/.brew/opt/readline/lib
endif

%.o : %.c
	@echo $(Y)Compiling [$<]...$(X)
	@$(CC) $(CFLAGS) $(INCLUDES_BONUS) $(INCLUDES) -c -o $@ $<

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

clean_bonus:
	@$(RM) $(OBJECTS_BONUS)
	@echo $(R)Removed following objects: [$(OBJECTS_BONUS)]$(X)

fclean_bonus: clean_bonus
	@$(RM) $(NAME_BONUS)
	@echo $(R)Removed following executable: [$(NAME_BONUS)]$(X)

re: fclean all

norma:
	@echo $(B)Checking Norminette...$(X)
	@norminette $(CFILES) ./include

norma_bonus:
	@echo $(B)Checking Norminette...$(X)
	@norminette $(CFILES_BONUS) ./bonus/include

$(NAME_BONUS): $(OBJECTS_BONUS)
	@echo $(G)Finished Compiling of [$(CFILES_BONUS)]$(X)
	@echo
	@echo $(Y)Compiling [$(NAME_BONUS)]...$(X)
	@$(CC) $(CFLAGS) $(INCLUDES_BONUS) $(OBJECTS_BONUS) -o $(NAME_BONUS) $(RL)
	@echo $(G)Finished Compiling of [$(NAME_BONUS)]$(X)

bonus: $(NAME_BONUS)

re_bonus: fclean_bonus bonus

.PHONY: all clean fclean re norma bonus clean_bonus fclean_bonus norma_bonus re_bonus
