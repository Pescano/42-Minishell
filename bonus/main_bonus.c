/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:06:15 by paescano          #+#    #+#             */
/*   Updated: 2023/10/26 12:06:38 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

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
