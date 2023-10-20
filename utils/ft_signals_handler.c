/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:19:39 by paescano          #+#    #+#             */
/*   Updated: 2023/10/20 11:23:32 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
