/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_match_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:57:31 by paescano          #+#    #+#             */
/*   Updated: 2023/10/26 12:05:32 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static int	ft_check_last_arg(char *file, char *arg)
{
	if ((g_global.ast.finish == 0)
		&& (ft_strlen(file) - ft_strlen(arg) < 0
			|| ft_strncmp(&file[ft_strlen(file) - ft_strlen(arg)],
				arg, ft_strlen(arg))))
		return (0);
	return (1);
}

static int	ft_check_first_arg(char *file, char *arg)
{
	if (g_global.ast.start == 0 && ft_strncmp(file, arg,
			ft_strlen(arg)))
		return (0);
	return (1);
}

int	ft_find_match(char *file, char **arg_splitted)
{
	int		m;
	char	*found;

	m = 0;
	found = file;
	while (found && *found && arg_splitted[m])
	{
		if (m == 0 && !ft_check_first_arg(file, arg_splitted[m]))
			return (0);
		else if (arg_splitted[m + 1] == NULL
			&& !ft_check_last_arg(file, arg_splitted[m]))
			return (0);
		found = ft_strnstr(found, arg_splitted[m], ft_strlen(found));
		if (found == NULL)
			return (0);
		found = found + ft_strlen(arg_splitted[m]);
		m++;
	}
	if (arg_splitted[m] != NULL)
		return (0);
	return (1);
}
