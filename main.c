/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:48:50 by paescano          #+#    #+#             */
/*   Updated: 2023/10/25 12:56:53 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// debug leaks
static void	ft_leaks(void)
{
	system("leaks minishell");
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
			else if (g_global.n_cmds > 1)
				ft_multiple_cmds();
			if (!access("tmp.txt", F_OK))
				unlink("tmp.txt");
			ft_free_cmd();
		}
	}
	free(input);
}

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	//atexit(ft_leaks);
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
