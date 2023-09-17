/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:53:23 by paescano          #+#    #+#             */
/*   Updated: 2023/09/17 19:55:40 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <fcntl.h>
# include <signal.h>
# include <unistd.h>
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

//signals handler
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
 * @brief insert a new enviroment variable
 * 
 * @param key name of the variable
 * @param value value of the variable
 */
void	ft_insert_env(char *key, char *value);

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

#endif