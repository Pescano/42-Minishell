/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:08:13 by paescano          #+#    #+#             */
/*   Updated: 2023/10/25 18:08:30 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_env(char *arg)
{
	int	i;

	i = 0;
	if (arg || !ft_getenv("PATH"))
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
