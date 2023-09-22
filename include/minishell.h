/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:53:23 by paescano          #+#    #+#             */
/*   Updated: 2023/09/21 16:51:12 by lromero-         ###   ########.fr       */
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

// Structs
typedef struct s_env
{
	char			*key;
	char			*value;
}	t_env;

typedef struct s_global
{
	int		exit_status;
	int		fd_in;
	int		fd_out;
	int		n_env;
	t_env	*env;
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
 * @return int returns 0 if the strings are equal, the difference in ascii values between them if not
 */
int		ft_strcmp(char *s1, char *s2);
/**
 * @brief creates a new string from another one
 * 
 * @param s the source string
 * @param start the starting position inside the source string
 * @param len the number of characters copied from "start"
*/
char	*ft_substr(char const *s, unsigned int start, size_t len);

// execute
/**
 * @brief prints the environment variables
 * 
*/
void	ft_env(void);
/**
 * @brief inserts or updates the given environment variable
 * 
 * @param str the environment variable to set in "key=value" format
*/
void	ft_export(char *str);
/**
 * @brief deletes an environment variable
 * 
 * @param key the name of the varable to remove
*/
void	ft_unset(char *key);
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

#endif