/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:22:27 by paescano          #+#    #+#             */
/*   Updated: 2023/10/26 12:22:39 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static size_t	setsize(size_t len, size_t slen, unsigned int start)
{
	if (start > slen)
		return (1);
	else if (len <= slen - start)
		return (len + 1);
	else
		return (slen - start + 1);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	pos;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	res = malloc(setsize(len, slen, start));
	if (!res)
		return (NULL);
	if (slen < start)
		*res = '\0';
	else
	{
		s += start;
		pos = 0;
		while (pos < len && s[pos] != '\0')
		{
			res[pos] = s[pos];
			pos++;
		}
		res[pos] = '\0';
	}
	return (res);
}
