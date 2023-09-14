/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:53:23 by paescano          #+#    #+#             */
/*   Updated: 2023/09/13 17:38:47 by paescano         ###   ########.fr       */
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

typedef struct s_global
{
	int		exit_status;
	int		fd_in;
	int		fd_out;
	char	**env;
}	t_global;

// initailization
/**
 * @brief initializes the minishell
 * 
 */
void	ft_init_minishell(void);

//signals handler
/**
 * @brief handler for SIGINT, prints a new line and clears the line
 * 
 * @param sig signal number
 */
void	ft_handler_contrl_c(int sig);
/**
 * @brief handler for SIGTERM, exits the program
 * 
 * @param sig signal number
 */
void	ft_handler_contrl_d(int sig);

// utils
/**
 * @brief frees all the allocated memory
 * 
 */
void	ft_free_all(void);

#endif