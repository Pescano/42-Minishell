/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:41:57 by paescano          #+#    #+#             */
/*   Updated: 2023/09/23 14:56:34 by lromero-         ###   ########.fr       */
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