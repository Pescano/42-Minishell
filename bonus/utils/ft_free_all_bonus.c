/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:12:57 by paescano          #+#    #+#             */
/*   Updated: 2023/10/26 12:13:06 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

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
	if (g_global.cmd_splitted)
		ft_freevpp((void **)g_global.cmd_splitted);
	if (g_global.cmd)
		ft_free_cmd();
	if (!access("tmp.txt", F_OK))
		unlink("tmp.txt");
	ft_reset_fds();
	printf("%s", error);
	exit(EXIT_FAILURE);
}

void	ft_freepp(void **pptr, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(pptr[i++]);
	free(pptr);
}

void	ft_freevpp(void **pptr)
{
	int	i;

	i = 0;
	while (pptr[i])
		free(pptr[i++]);
	free(pptr);
}
