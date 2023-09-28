/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:11:46 by paescano          #+#    #+#             */
/*   Updated: 2023/09/28 19:22:30 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_arglen(char *arg, int i, char quote)
{
	int	len;

	len = 2;
	while (arg[i] && arg[i] != quote)
	{
		len++;
		i++;
	}
	return (len);
}

char	*ft_split_quotes(char *input, int *i, char quote)
{
	char	*arg;
	int		j;
	int		k;
	int		len;

	k = *i + 1;
	len = ft_arglen(input, k, quote);
	arg = (char *)malloc(sizeof(char) * (len + 1));
	if (!arg)
		ft_free_error(ERROR_MALLOC);
	j = 1;
	arg[0] = quote;
	while (input[k] != quote)
	{
		arg[j] = input[k];
		j++;
		k++;
	}
	arg[j] = quote;
	*i += len;
	return (arg);
}
