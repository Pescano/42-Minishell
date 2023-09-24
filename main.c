/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:48:50 by paescano          #+#    #+#             */
/*   Updated: 2023/09/22 12:39:15 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// debug leaks
static void	ft_leaks(void)
{
	system("leaks minishell");
}

static void	ft_execute_minishell(char **env)
{
	char	*input;

	input = readline("minishell >");
	if (!input)
		ft_handler_ctrl_d(input);
	if (input[0])
		add_history(input);
//	ft_lexer(input);
	char *test = ft_strdup("-n");
	char *test2 = ft_strdup("adios");
	char *a[3];
	a[0] = test;
	a[1] = test2;
	a[2] = NULL;
	ft_echo(a);
	free(test);
	free(test2);
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
		ft_execute_minishell(env);
	}
	ft_free_all();
	return (0);
}
