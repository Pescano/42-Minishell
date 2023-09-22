/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:34:57 by lromero-          #+#    #+#             */
/*   Updated: 2023/09/21 16:46:21 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(void)
{
	printf("%s\n", ft_getenv("PWD"));
}

void	ft_cd(char *path)
{
	char	*temp;
	char	*new;

	temp = ft_getenv("PWD");
	if (chdir(path))
	{
		//error msg
		return ;
	}
	new = malloc(PATH_MAX);
	if (!new)
		ft_free_error(ERROR_MALLOC);
	if (!getcwd(new, PATH_MAX))
	{
		free(new);
		//error msg
		return ;
	}
	if (!temp)
		ft_update_env(ft_strdup("OLDPWD"), ft_strdup(""));
	else
		ft_update_env(ft_strdup("OLDPWD"), ft_strdup(temp));
	ft_update_env(ft_strdup("PWD"), new);
}
