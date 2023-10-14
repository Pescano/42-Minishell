/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:23:19 by lromero-          #+#    #+#             */
/*   Updated: 2023/10/14 11:55:18 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(char *arg)
{
	int	i;

	i = 0;
	if (arg)
	{
		ft_print_error("env: ", NULL);
		ft_print_error(ERROR_FILE, arg);
		return (127);
	}
	while (i < g_global.n_env)
	{
		printf("%s=%s\n", g_global.env[i].key, g_global.env[i].value);
		i++;
	}
	return (0);
}

int	ft_unset(char **key)
{
	while (*key)
	{
		if (ft_getenv((*key)))
			ft_delete_one_env((*key));
		key++;
	}
	return (0);
}
