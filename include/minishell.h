/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:53:23 by paescano          #+#    #+#             */
/*   Updated: 2023/10/09 13:30:41 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <fcntl.h>
# include <signal.h>
# include <unistd.h>
# include <limits.h>
# include <sys/ioctl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "get_next_line.h"
# include "error_messages.h"

// Colors
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define WHITE "\033[0m"

// Quotes states
# define NO_QUOTES 0
# define DOUBLE_QUOTE_INCOMPLETE 1
# define DOUBLE_QUOTE_COMPLETE 2
# define SINGLE_QUOTE_IMCOMPLETE 3
# define SINGLE_QUOTE_COMPLETE 4

// Tokens
enum e_tokens {
	PIPE = '|',
	SINGLE_QUOTE = '\'',
	DOUBLE_QUOTE = '\"',
	LESS = '<',
	GREAT = '>',
	TABS = '\t',
	SPACES = ' ',
};

// Structs
typedef struct s_cmd
{
	int				in;
	int				out;
	char			**cmds;
	char			**fd_in;
	char			**fd_in2;
	char			**fd_out;
	char			**fd_out2;
}	t_cmd;

typedef struct s_lexer
{
	int				quotes_state;
	int				pipe_state;
}	t_lexer;

typedef struct s_env
{
	char			*key;
	char			*value;
}	t_env;

typedef struct s_global
{
	int		exit_status;
	int		n_env;
	int		n_cmds;
	char	**cmd_splitted;
	t_lexer	lexer;
	t_env	*env;
	t_cmd	*cmd;
}	t_global;

// Global variables
t_global	g_global;

// initailization
/**
 * @brief initializes the minishell
 * 
 * @param env eviroment variables
 */
void	ft_init_minishell(char **env);
/**
 * @brief initializes the enviroment variables
 * 
 * @param env enviroment variables
 */
void	ft_init_env(char **env);

// signals handler
/**
 * @brief handler for SIGINT, prints a new line and clears the line
 * 
 * @param sig signal number
 */
void	ft_handler_ctrl_c(int sig);
/**
 * @brief handler for SIGTERM, exits the program
 * 
 * @param char * input
 */
void	ft_handler_ctrl_d(char *input);

// handlers
/**
 * @brief insert a new environment variable or updates an existing one
 * 
 * @param key name of the variable
 * @param value value of the variable
 */
void	ft_update_env(char *key, char *value);
/**
 * @brief deletes an environment variable
 * 
 * @param key key of the variable to delete
 */
void	ft_delete_one_env(char *key);
/**
 * @brief returns the value of a environment variable
 * 
 * @param key key of the variable to search
*/
char	*ft_getenv(char *key);
/**
 * @brief initializes the command structure
 * 
 */
void	ft_init_cmd(void);
/**
 * @brief frees the command structure
 * 
 */
void	ft_free_cmd(void);
/**
 * @brief adds a redirection to the command structure
 * 
 * @param redir redirection to add
 * @param arg argument of the redirection
 * @param i variable to know if it is an single or double redirection
 */
void	ft_add_redir_cmd(char *redir, char *arg, int i);

// lexer 
/**
 * @brief checks if the syntax of the command is correct
 * 
 * @param cmd command to check 
 * @return int 1 if the syntax is correct, 0 if not
 */
int		ft_lexer(char *cmd);
/**
 * @brief checks if the quotes are closed
 * 
 * @param cmd command to check
 * @return int 1 if the quotes are closed, 0 if not
 */
int		ft_check_quotes(char *cmd);
/**
 * @brief set a new quotes state
 * 
 * @param c character that sets the new state
 */
void	ft_set_quote_state(char c);
/**
 * @brief check the syntax of the pipes
 * 
 * @param cmd command to check
 * @return int 1 if the syntax is correct, 0 if not
 */
int		ft_check_pipes(char *cmd);
/**
 * @brief check the syntax of the redirections
 * 
 * @param cmd command to check
 * @return int 1 if the syntax is correct, 0 if not
 */
int		ft_check_redir(char *cmd);

// parser
/**
 * @brief parses the command and modifies the global variables
 * 
 * @param input command to parse
 */
void	ft_parser(char *input);
/**
 * @brief splits the command into several commands by the pipes
 * 
 * @param input command to split
 */
void	ft_split_pipe(char *input);
/**
 * @brief split the command without spacial characters
 * 
 * @param input command to split
 * @param i position of the command
 * @return char* command splitted0
 */
char	*ft_split_normal(char *input, int *i);
/**
 * @brief splits the command by the redirections
 * 
 * @param input command to split
 */
char	**ft_split_redir(char *input);
/**
 * @brief expands the environment variables
 * 
 * @param cmd command to expand
 * @return char** command expanded
 */
char	**ft_expand_vars(char **cmd);
/**
 * @brief expand the quotes from the command
 * 
 * @param cmd command to expand the quotes
 * @return char** command without quotes
 */
char	**ft_expand_quotes(char **cmd);

// utils
/**
 * @brief frees all the allocated memory
 * 
 */
void	ft_free_all(void);
/**
 * @brief frees a string and prints an error message
 * 
 * @param error message to print
 */
void	ft_free_error(char *error);
/**
 * @brief duplicates a string
 * 
 * @param s1 string to duplicate 
 * @return char* string duplicated
 */
char	*ft_strdup(char *s1);
/**
 * @brief divides a string into several strings according to a delimiter
 * 
 * @param s string to divide
 * @param c delimiter
 * @return char** strings divided
 */
char	**ft_split(char *s, char c);
/**
 * @brief compares two strings
 * 
 * @param s1 string 1
 * @param s2 string 2
 * @return int returns 0 if the strings are equal, the difference in 
 * ascii values between them if not
 */
int		ft_strcmp(char *s1, char *s2);
/**
 * @brief creates a new string from another one
 * 
 * @param s the source string
 * @param start the starting position inside the source string
 * @param len the number of characters copied from "start"
*/
char	*ft_substr(char *s, unsigned int start, size_t len);
/**
 * @brief frees the memory of a char **
 * 
 * @param pptr the char ** to free
 * @param n the number of strings inside pptr
*/
void	ft_freepp(void **pptr, int n);
/**
 * @brief frees the memory of a null terminated char **
 * 
 * @param pptr the string array to free
*/
void	ft_freevpp(void **pptr);
/**
 * @brief returns a null terminated char ** with each line 
 * being an environment variable
*/
char	**ft_format_env(void);
/**
 * @brief creates a new string concatenating 2 strings
 * 
 * @param s1 the first string
 * @param s2 the second string
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
/**
 * @brief overwrites the destination string with another one
 * 
 * @param dst the string to overwrite
 * @param src the string to copy
 * @param dstsize the maximum amount of characters to copy
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
/**
 * @brief returns the length of a null terminated char **
 * 
 * @param pp pointer to the string array
 * @return int size of the string array
 */
int		ft_pplen(char **pp);
/**
 * @brief adds a string to a null terminated char **
 * 
 * @param arg string to add
 * @param strs string array
 * @return char** string array with the new string
 */
char	**ft_add_pp(char *arg, char **strs);
/**
 * @brief replace environment variables with their values
 * 
 * @param str command to replace
 * @param start before the dollar sign
 * @param end after the variable name
 * @param mid value of the variable
 * @return char* command with the variable replaced
 */
char	*ft_replace_str(char *str, char *start, char *end, char *mid);
/**
 * @brief converts an integer to a string
 * 
 * @param n integer to convert
 * @return char* converted integer
 */
char	*ft_itoa(int n);
/**
 * @brief checks if a character is a digit or aplhabetical
 * 
 * @param c character to check 
 * @return int returns 1 if the character is a digit or alphabetical, 0 if not
 */
int		ft_isalnum(int c);

// execute
/**
 * @brief prints the environment variables
 * 
*/
void	ft_env(void);
/**
 * @brief inserts or updates the given environment variable
 * 
 * @param str a null terminated array with the environment 
 * variables to set in "key=value" format
 * 
*/
void	ft_export(char **str);
/**
 * @brief deletes an environment variable
 * 
 * @param key a null terminated array of strings with 
 * the names of the variables to unset
*/
void	ft_unset(char **key);
/**
 * @brief prints the current working directory
*/
void	ft_pwd(void);
/**
 * @brief changes the current working directory
 * 
 * @param path the path to the new working directory
*/
void	ft_cd(char *path);
/**
 * @brief prints strings passed as arguments
 * 
 * @param args a null terminated array of strings to print.
 * if the first argument is "-n" it won't print a newline
*/
void	ft_echo(char **args);

#endif