/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:14:46 by paescano          #+#    #+#             */
/*   Updated: 2023/09/29 16:57:32 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_arglen(char *input, int i)
{
	int	len;

	len = 0;
	while (input[i] && input[i] != SPACES && input[i] != LESS
		&& input[i] != GREAT && input[i] != PIPE && input[i] != DOUBLE_QUOTE
		&& input[i] != SINGLE_QUOTE)
	{
		len++;
		i++;
	}
	return (len);
}

char	*ft_split_normal(char *input, int *i)
{
	char	*arg;
	int		x;
	int		j;
	int		len;

	len = ft_arglen(input, *i);
	arg = (char *)malloc(sizeof(char) * (len + 1));
	j = *i;
	x = 0;
	while (j < len + *i)
	{
		arg[x] = input[j];
		x++;
		j++;
	}
	*i += len;
	return (arg);
}
