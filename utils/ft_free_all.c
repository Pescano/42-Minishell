/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:41:57 by paescano          #+#    #+#             */
/*   Updated: 2023/09/17 19:46:33 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_free_env(void)
{
	int	i;

	i = 0;
	if (!g_global.env)
		return ;
	while (g_global.env[i].key != NULL && g_global.env[i].value != NULL)
	{
		free(g_global.env[i].key);
		free(g_global.env[i].value);
		i++;
	}
	free(g_global.env);
}

void	ft_free_all(void)
{
	rl_clear_history();
	ft_free_env();
}

void	ft_free_error(char *error)
{
	ft_free_all();
	printf("%s", error);
	exit(EXIT_FAILURE);
}
