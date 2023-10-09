/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:14:46 by paescano          #+#    #+#             */
/*   Updated: 2023/10/03 16:47:00 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_arglen(char *input, int i)
{
	int		len;
	char	quote;

	len = 0;
	quote = '\0';
	while (input[i])
	{
		if (input[i] == DOUBLE_QUOTE || input[i] == SINGLE_QUOTE)
		{
			if (quote == '\0')
				quote = input[i];
			else if (quote == input[i])
				quote = '\0';
		}
		else if (quote == '\0' && (input[i] == SPACES || input[i] == LESS
				|| input[i] == GREAT))
			break ;
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
	arg[x] = '\0';
	*i += len;
	return (arg);
}
