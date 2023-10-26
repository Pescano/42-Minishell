/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_ast_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:21:36 by paescano          #+#    #+#             */
/*   Updated: 2023/10/26 12:05:27 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_find_ast(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '*')
			return (1);
		else if (str[i] == DOUBLE_QUOTE)
		{
			i++;
			while (str[i] != DOUBLE_QUOTE)
				i++;
		}
		else if (str[i] == SINGLE_QUOTE)
		{
			i++;
			while (str[i] != SINGLE_QUOTE)
				i++;
		}
		i++;
	}
	return (0);
}
