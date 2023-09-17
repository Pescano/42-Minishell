/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:36:27 by paescano          #+#    #+#             */
/*   Updated: 2023/09/17 19:55:15 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_insert_env(char *key, char *value)
{
	t_env	*tmp;
	int		i;

	i = 0;
	g_global.n_env++;
	tmp = (t_env *)malloc(sizeof(t_env) * g_global.n_env + 1);
	tmp[g_global.n_env].key = NULL;
	if (!tmp)
		ft_free_error(ERROR_MALLOC);
	while (i < g_global.n_env - 2)
	{
		tmp[i].key = g_global.env[i].key;
		tmp[i].value = g_global.env[i].value;
		i++;
	}
	tmp[i].key = key;
	tmp[i].value = value;
	tmp[i + 1].key = g_global.env[i + 1].key;
	tmp[i + 1].value = g_global.env[i + 1].value;
	if (g_global.env)
		free(g_global.env);
	g_global.env = tmp;
}
