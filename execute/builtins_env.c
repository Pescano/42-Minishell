/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:23:19 by lromero-          #+#    #+#             */
/*   Updated: 2023/10/05 14:04:54 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(void)
{
	int	i;

	i = 0;
	while (i < g_global.n_env)
	{
		printf("%s=%s\n", g_global.env[i].key, g_global.env[i].value);
		i++;
	}
}

static void	ft_print_export(void)
{
	int	i;
	int	j;
	int	prev;
	int	curr;

	i = 0;
	curr = 0;
	prev = -1;
	while (i++ < g_global.n_env)
	{
		j = 0;
		while (j < g_global.n_env)
		{
			if (curr >= 0 && curr != j
				&& ft_strcmp(g_global.env[j].key, g_global.env[curr].key < 0)
				&& (prev < 0 || (j != prev
				&& ft_strcmp(g_global.env[j].key, g_global.env[prev].key) > 0)))
				curr = j;
			j++;
		}
	}
}

void	ft_export(char **str)
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
		{
			free(key);
			ft_free_error(ERROR_MALLOC);
		}
		ft_update_env(key, val);
		str++;
	}
}

void	ft_unset(char **key)
{
	while (*key)
	{
		if (ft_getenv((*key)))
			ft_delete_one_env((*key));
		key++;
	}
}
