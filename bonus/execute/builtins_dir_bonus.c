/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_dir_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:54:36 by paescano          #+#    #+#             */
/*   Updated: 2023/10/25 17:54:53 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_pwd(void)
{
	printf("%s\n", ft_getenv("PWD"));
	return (0);
}

int	ft_cd(char *path)
{
	char	*temp;
	char	*new;

	if (!path)
		return (0);
	temp = ft_getenv("PWD");
	if (chdir(path))
	{
		ft_print_error(ERROR_FILE, path);
		return (1);
	}
	new = malloc(PATH_MAX);
	if (!new)
		ft_free_error(ERROR_MALLOC);
	if (!getcwd(new, PATH_MAX))
	{
		free(new);
		ft_free_error(ERROR_CWD);
	}
	if (!temp)
		ft_update_env(ft_strdup("OLDPWD"), ft_strdup(""));
	else
		ft_update_env(ft_strdup("OLDPWD"), ft_strdup(temp));
	ft_update_env(ft_strdup("PWD"), new);
	return (0);
}
