/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ast_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:40:42 by paescano          #+#    #+#             */
/*   Updated: 2023/10/26 12:05:42 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static void	ft_set_ast(char *arg)
{
	if (*arg == '*')
		g_global.ast.start = 1;
	if (arg[ft_strlen(arg) - 1] == '*')
		g_global.ast.finish = 1;
}

static int	ft_len_ast(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i + len] && str[i + len] != '*')
	{
		if (str[i + len] == DOUBLE_QUOTE)
		{
			len++;
			while (str[i + len] != DOUBLE_QUOTE)
				len++;
			len++;
		}
		else if (str[i + len] == SINGLE_QUOTE)
		{
			len++;
			while (str[i + len] != SINGLE_QUOTE)
				len++;
			len++;
		}
		else
			len++;
	}
	return (len);
}

char	**ft_split_arg(char *arg)
{
	int		i;
	int		len;
	char	**arg_splitted;

	i = 0;
	arg_splitted = NULL;
	ft_set_ast(arg);
	while (arg[i])
	{
		len = ft_len_ast(arg, i);
		if (len)
			arg_splitted = ft_add_pp(ft_remove_quotes(
						ft_substr(&arg[i], 0, len)), arg_splitted);
		i += len;
		while (arg[i] == '*')
			i++;
	}
	if (!arg_splitted)
		arg_splitted = ft_add_pp(ft_strdup(""), arg_splitted);
	return (arg_splitted);
}
