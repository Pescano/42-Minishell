/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_com_path_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:09:59 by paescano          #+#    #+#             */
/*   Updated: 2023/10/26 12:10:09 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static char	*pathcat(char *com, char *path)
{
	char	*res;
	int		i;

	if (!com || !path)
		return (NULL);
	res = malloc((ft_strlen(com) + ft_strlen(path) + 2) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (*path)
		res[i++] = *path++;
	res[i++] = '/';
	while (*com)
		res[i++] = *com++;
	res[i] = '\0';
	return (res);
}

char	**ft_com_path(char **com)
{
	char	*compath;
	char	**paths;
	int		i;

	paths = ft_split(ft_getenv("PATH"), ':');
	i = 0;
	compath = NULL;
	while (paths && paths[i])
	{
		compath = pathcat(com[0], paths[i]);
		if (!access(compath, F_OK & X_OK))
			break ;
		if (compath)
			free(compath);
		compath = NULL;
		i++;
	}
	if (compath)
	{
		free(com[0]);
		com[0] = compath;
	}
	if (paths)
		ft_freevpp((void **)paths);
	return (com);
}
