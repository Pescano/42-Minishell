/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:34:57 by lromero-          #+#    #+#             */
/*   Updated: 2023/10/30 13:36:35 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	printf("%s\n", ft_getenv("PWD"));
	return (0);
}

int	ft_cd(char *path)
{
	char	*temp;
	char	*new;

	temp = ft_getenv("PWD");
	if (!path)
	{
		if (chdir(ft_strjoin(ft_strdup("/Users/"), getenv("USER"))))
			return (ft_print_error(ERROR_FILE, path), 1);
	}
	else if (chdir(path))
		return (ft_print_error(ERROR_FILE, path), 1);
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
