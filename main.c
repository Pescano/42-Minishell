/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:48:50 by paescano          #+#    #+#             */
/*   Updated: 2023/10/14 13:41:56 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// debug leaks
static void	ft_leaks(void)
{
	system("leaks minishell");
}

//testing//ft_print_cmds();
static void	ft_print_cmds(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_global.n_cmds)
	{
		j = 0;
		if (g_global.cmd[i].cmds != NULL)
		{
			while (g_global.cmd[i].cmds[j])
			{
				printf("cmd[%d]: %s\n", i, g_global.cmd[i].cmds[j]);
				j++;
			}
		}
		j = 0;
		if (g_global.cmd[i].fd_in != NULL)
		{
			while (g_global.cmd[i].fd_in[j])
			{
				printf("fd_in[%d]: %s\n", i, g_global.cmd[i].fd_in[j]);
				j++;
			}
		}
		j = 0;
		if (g_global.cmd[i].fd_in2 != NULL)
		{
			while (g_global.cmd[i].fd_in2[j])
			{
				printf("fd_in2[%d]: %s\n", i, g_global.cmd[i].fd_in2[j]);
				j++;
			}
		}
		j = 0;
		if (g_global.cmd[i].fd_out != NULL)
		{
			while (g_global.cmd[i].fd_out[j])
			{
				printf("fd_out[%d]: %s\n", i, g_global.cmd[i].fd_out[j]);
				j++;
			}
		}
		j = 0;
		if (g_global.cmd[i].fd_out2 != NULL)
		{
			while (g_global.cmd[i].fd_out2[j])
			{
				printf("fd_out2[%d]: %s\n", i, g_global.cmd[i].fd_out2[j]);
				j++;
			}
		}
		printf("in: %d\n", g_global.cmd[i].in);
		printf("out %d\n", g_global.cmd[i].out);
		i++;
	}
}

static void	ft_execute_minishell(void)
{
	char	*input;
	char	*prompt;

	prompt = ft_set_prompt();
	input = readline(prompt);
	free(prompt);
	if (!input)
		ft_handler_ctrl_d(input);
	if (input[0])
	{
		add_history(input);
		if (ft_lexer(input))
		{
			ft_parser(input);
			if (g_global.n_cmds == 1)
				ft_single_command();
			ft_free_cmd();
		}
	}
	free(input);
}

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	atexit(ft_leaks);
	if (argc != 1)
		exit(0);
	ft_init_minishell(env);
	while (1)
	{
		ft_execute_minishell();
	}
	ft_free_all();
	return (0);
}
