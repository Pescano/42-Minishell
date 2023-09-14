/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:48:50 by paescano          #+#    #+#             */
/*   Updated: 2023/09/14 12:52:38 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_global	g_global;

static void	ft_leaks(void)
{
	system("leaks minishell");
}

static void	ft_execute_minishell(void)
{
	char	*line;

	line = readline("minishell >");
	if (line && line[0] != '\0')
		add_history(line);
	free(line);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	atexit(ft_leaks);
	ft_init_minishell();
	while (1)
	{
		ft_execute_minishell();
	}
	ft_free_all();
	return (0);
}
