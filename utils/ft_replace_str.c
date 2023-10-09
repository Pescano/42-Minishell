/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:27:50 by paescano          #+#    #+#             */
/*   Updated: 2023/10/07 19:33:49 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_get_first_ocurrence(char *str, char *substr)
{
	int	i;

	i = 0;
	if (!substr || !substr[0])
		return ((int)ft_strlen(str));
	while (str + i != substr || !*(str + i))
	{
		i++;
	}
	return (i);
}

char	*ft_replace_str(char *str, char *start, char *end, char *mid)
{
	char	*left;
	char	*right;
	char	*aux;
	char	*final;

	left = ft_substr(str, 0, ft_get_first_ocurrence(str, start));
	right = ft_substr(str, ft_get_first_ocurrence(str, end), ft_strlen(str));
	aux = ft_strjoin(left, mid);
	final = ft_strjoin(aux, right);
	free(right);
	free(str);
	return (final);
}
