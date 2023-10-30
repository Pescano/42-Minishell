/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_ast_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:18:22 by paescano          #+#    #+#             */
/*   Updated: 2023/10/30 13:16:40 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

char	**ft_replace_ast(char **arg_splitted)
{
	DIR				*directory;
	char			**files;
	char			*filename;
	struct dirent	*aux;

	directory = opendir(".");
	aux = readdir(directory);
	files = NULL;
	g_global.ast.n = 0;
	while (aux != NULL)
	{
		filename = aux->d_name;
		if (ft_find_match(filename, arg_splitted) == 1)
		{
			files = ft_add_pp(ft_strdup(filename), files);
			g_global.ast.n++;
		}
		aux = readdir(directory);
	}
	closedir(directory);
	ft_freevpp((void **)arg_splitted);
	return (files);
}

static char	**ft_change_ast(char *arg, char **c, int n)
{
	char	**expand_args;
	char	**tmp;
	int		i;

	g_global.ast.start = 0;
	g_global.ast.finish = 0;
	tmp = NULL;
	i = 0;
	expand_args = ft_replace_ast(ft_split_arg(arg));
	if (n > 0 && g_global.ast.n > 1 && ((!c[n - 1][1]
			&& (c[n - 1][0] == '>' || c[n - 1][0] == '<'))
			|| (c[n - 1][0] == '>' && c[n - 1][1] == '>' && !c[n - 1][2])))
		g_global.ast.flag = 1;
	if (expand_args == NULL)
		tmp = ft_add_pp(ft_strdup(arg), tmp);
	else
	{
		while (expand_args[i])
		{
			tmp = ft_add_pp(ft_strdup(expand_args[i]), tmp);
			i++;
		}
		ft_freevpp((void **)expand_args);
	}
	return (tmp);
}

char	**ft_expand_ast(char **cmd)
{
	char	**tmp;
	char	**tmp2;
	int		i;
	int		j;

	i = 0;
	tmp = NULL;
	while (cmd[i])
	{
		if (!ft_find_ast(cmd[i])
			|| (i > 0 && cmd[i - 1][0] == '<' && cmd[i - 1][1] == '<'))
			tmp = ft_add_pp(ft_strdup(cmd[i]), tmp);
		else
		{
			tmp2 = ft_change_ast(cmd[i], cmd, i);
			j = 0;
			while (tmp2[j])
				tmp = ft_add_pp(ft_strdup(tmp2[j++]), tmp);
			ft_freevpp((void **)tmp2);
		}
		i++;
	}
	return (ft_freevpp((void **)cmd), tmp);
}
