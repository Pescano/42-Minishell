/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:36:27 by paescano          #+#    #+#             */
/*   Updated: 2023/10/02 18:24:32 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_insert_env(char *key, char *value)
{
	t_env	*tmp;
	int		i;

	i = 0;
	g_global.n_env++;
	tmp = (t_env *)malloc(sizeof(t_env) * g_global.n_env + 1);
	if (!tmp)
		ft_free_error(ERROR_MALLOC);
	tmp[g_global.n_env].key = NULL;
	while (i < g_global.n_env - 2)
	{
		tmp[i].key = g_global.env[i].key;
		tmp[i].value = g_global.env[i].value;
		i++;
	}
	tmp[i].key = key;
	tmp[i].value = value;
	tmp[i + 1].key = g_global.env[i].key;
	tmp[i + 1].value = g_global.env[i].value;
	if (g_global.env)
		free(g_global.env);
	g_global.env = tmp;
}

void	ft_update_env(char *key, char *value)
{
	int	i;

	i = 0;
	while (i < g_global.n_env)
	{
		if (ft_strcmp(g_global.env[i].key, key) == 0)
		{
			free(key);
			free(g_global.env[i].value);
			g_global.env[i].value = value;
			return ;
		}
		i++;
	}
	ft_insert_env(key, value);
}

void	ft_free_env(char *key, char *value)
{
	free(key);
	free(value);
}

void	ft_delete_one_env(char *key)
{
	t_env	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	g_global.n_env--;
	tmp = (t_env *)malloc(sizeof(t_env) * g_global.n_env + 1);
	tmp[g_global.n_env].key = NULL;
	if (!tmp)
		ft_free_error(ERROR_MALLOC);
	while (i < g_global.n_env + 1)
	{
		if (ft_strcmp(g_global.env[i].key, key) != 0)
		{
			tmp[j].key = g_global.env[i].key;
			tmp[j].value = g_global.env[i].value;
			j++;
		}
		else
			ft_free_env(g_global.env[i].value, g_global.env[i].key);
		i++;
	}
	free(g_global.env);
	g_global.env = tmp;
}

char	*ft_getenv(char *key)
{
	int	i;

	i = 0;
	while (i < g_global.n_env)
	{
		if (!ft_strcmp(key, g_global.env[i].key))
			return (g_global.env[i].value);
		i++;
	}
	return (NULL);
}
