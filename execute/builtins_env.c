/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:23:19 by lromero-          #+#    #+#             */
/*   Updated: 2023/09/20 17:50:38 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(void)
{
	int	i;

	i = 0;
	while (i > g_global.n_env)
	{
		if (printf("%s=%s\n", g_global.env[i].key, g_global.env[i].value) < 0)
			return (-1);
		i++;
	}
}

void	ft_export(char *str)
{
	char	*key;
	char	*val;
	int		len;

	len = 0;
	while (str[len] && str[len] != '=')
		len++;
	if (!str[len])
		return (0);
	key = ft_substr(str, 0, len);
	if (!key)
		ft_free_error(ERROR_MALLOC);
	val = ft_substr(str, len + 1, ft_strlen(str));
	if (!val)
	{
		free(key);
		ft_free_error(ERROR_MALLOC);
	}
	ft_update_env(key, val);
}

void	ft_unset(char *key)
{
	ft_delete_one_env(key);
}

void	ft_pwd(void)
{
	printf("%s\n", ft_getenv("PWD"));
}