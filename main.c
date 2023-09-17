/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:48:50 by paescano          #+#    #+#             */
/*   Updated: 2023/09/17 19:32:33 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// debug leaks
static void	ft_leaks(void)
{
	system("leaks minishell");
}

// debug environment variables
static void	ft_print_env(void)
{
	int	i;

	i = 0;
	while (g_global.env[i].key != NULL || g_global.env[i].value != NULL)
	{
		printf("%s=%s\n", g_global.env[i].key, g_global.env[i].value);
		i++;
	}
}

static void	ft_execute_minishell(char **env)
{
	char	*input;

	input = readline("minishell >");
	if (!input)
		ft_handler_ctrl_d(input);
	if (input[0])
		add_history(input);
	ft_print_env();
	free(input);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	atexit(ft_leaks);
	ft_init_minishell(env);
	while (1)
	{
		ft_execute_minishell(env);
	}
	ft_free_all();
	return (0);
}
