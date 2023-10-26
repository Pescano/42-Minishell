/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals_handler_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:18:45 by paescano          #+#    #+#             */
/*   Updated: 2023/10/26 12:18:56 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_handler_ctrl_c(int sig)
{
	if (sig == SIGINT)
	{
		rl_on_new_line();
		rl_redisplay();
		write(1, "   \n", 4);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_global.exit_status = 1;
	}
}

void	ft_handler_ctrl_d(char *input)
{
	free(input);
	ft_free_all();
	if (!access("tmp.txt", F_OK))
		unlink("tmp.txt");
	write(1, "exit\n", 5);
	exit(g_global.exit_status);
}
