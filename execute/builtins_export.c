/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:41:11 by paescano          #+#    #+#             */
/*   Updated: 2023/10/13 13:08:26 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*ft_clone_env(void)
{
	t_env	*cpy;
	int		i;

	i = 0;
	cpy = (t_env *)malloc(sizeof(t_env) * g_global.n_env + 1);
	if (!cpy)
		ft_free_error(ERROR_MALLOC);
	while (i < g_global.n_env)
	{
		cpy[i].key = ft_strdup(g_global.env[i].key);
		cpy[i].value = ft_strdup(g_global.env[i].value);
		i++;
	}
	cpy[i].key = NULL;
	cpy[i].value = NULL;
	return (cpy);
}

static void	ft_free_env_cpy(t_env *env)
{
	int	i;

	i = 0;
	if (!env)
		return ;
	while (env[i].key != NULL && env[i].value != NULL)
	{
		free(env[i].key);
		free(env[i].value);
		i++;
	}
	free(env);
}

static void	ft_print(t_env *env)
{
	int	i;

	i = 0;
	while (env[i].key != NULL && env[i].value != NULL)
	{
		printf("declare -x %s=\"%s\"\n", env[i].key, env[i].value);
		i++;
	}
}

static void	ft_print_export(void)
{
	t_env	*cpy;
	t_env	tmp;
	int		i;
	int		j;

	cpy = ft_clone_env();
	i = 0;
	while (cpy[i].key != NULL && cpy[i].value != NULL)
	{
		j = i + 1;
		while (cpy[j].key != NULL && cpy[j].value != NULL)
		{
			if (strcmp(cpy[i].key, cpy[j].key) > 0)
			{
				tmp = cpy[i];
				cpy[i] = cpy[j];
				cpy[j] = tmp;
			}
			j++;
		}
		i++;
	}
	ft_print(cpy);
	ft_free_env_cpy(cpy);
}

int	ft_export(char **str)
{
	char	*key;
	char	*val;
	int		len;

	if (!*str)
		ft_print_export();
	while (*str)
	{
		len = 0;
		while ((*str)[len] && (*str)[len] != '=')
			len++;
		if (!len || !(*str)[len])
			return ;
		key = ft_substr((*str), 0, len);
		if (!key)
			ft_free_error(ERROR_MALLOC);
		val = ft_substr((*str), len + 1, ft_strlen((*str)));
		if (!val)
			return (free(key),ft_free_error(ERROR_MALLOC),  1);
		ft_update_env(key, val);
		str++;
	}
	return (0);
}
