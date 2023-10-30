/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_dir_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:54:36 by paescano          #+#    #+#             */
/*   Updated: 2023/10/30 17:07:32 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_pwd(void)
{
	printf("%s\n", ft_getenv("PWD"));
	return (0);
}

static int	ft_special_cd(char *path)
{
	char	*tmp;

	if (!path)
	{
		if (chdir(ft_strjoin(ft_strdup("/Users/"), getenv("USER"))))
			return (ft_print_error(ERROR_FILE, path), 1);
	}
	else if (ft_strcmp(path, "-") == 0)
	{
		tmp = ft_getenv("OLDPWD");
		if (!tmp)
			return (ft_print_error(ERROR_CD, "minishell: OLDPWD"), 1);
		else if (chdir(tmp))
			return (ft_print_error(ERROR_FILE, path), 1);
		printf("%s\n", tmp);
	}
	else if (ft_strcmp(path, "~") == 0)
	{
		tmp = ft_getenv("HOME");
		if (!tmp)
			return (ft_print_error(ERROR_CD, "minishell: HOME"), 1);
		if (chdir(ft_getenv("HOME")))
			return (ft_print_error(ERROR_FILE, path), 1);
	}
	return (0);
}

int	ft_cd(char *path)
{
	char	*temp;
	char	*new;

	temp = ft_getenv("PWD");
	if (ft_special_cd(path))
		return (1);
	else if (path && ft_strcmp(path, "-") && ft_strcmp(path, "~")
		&& chdir(path))
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
