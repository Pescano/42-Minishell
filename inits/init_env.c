/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:31:24 by paescano          #+#    #+#             */
/*   Updated: 2023/09/17 19:28:23 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_get_env_size(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	g_global.n_env = i;
}

static void	ft_add_env(char *env, int pos)
{
	char	*key;
	char	*value;
	int		i;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	g_global.env[pos].key = ft_strndup(env, i);
	g_global.env[pos].value = ft_strdup(env + i + 1);
}

void	ft_init_env(char **env)
{
	int	i;

	i = 0;
	if (!env)
		return ;
	ft_get_env_size(env);
	g_global.env = (t_env *)malloc(sizeof(t_env) * g_global.n_env + 1);
	if (!g_global.env)
	{
		printf("%s", ERROR_MALLOC);
		exit(EXIT_FAILURE);
	}		
	while (env[i])
	{
		ft_add_env(env[i], i);
		i++;
	}
	g_global.env[i].key = NULL;
	g_global.env[i].value = NULL;
}