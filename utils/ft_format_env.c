/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:48:54 by lromero-          #+#    #+#             */
/*   Updated: 2023/10/18 21:13:37 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_format_env(void)
{
	char	**re_env;
	char	*aux;
	int		i;

	re_env = malloc (sizeof(char *) * (g_global.n_env + 1));
	if (!re_env)
		return (NULL);
	re_env[g_global.n_env] = NULL;
	i = 0;
	while (i < g_global.n_env)
	{
		aux = ft_strjoin(ft_strdup(g_global.env[i].key), "=");
		if (!aux)
			return (ft_freepp((void **)re_env, i), NULL);
		re_env[i] = ft_strjoin(aux, g_global.env[i].value);
		if (!re_env)
			return (ft_freepp((void **)re_env, i), NULL);
		i++;
	}
	return (re_env);
}
