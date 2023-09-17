/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:53:08 by paescano          #+#    #+#             */
/*   Updated: 2023/09/17 17:16:06 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_num_words(char const *s, char c)
{
	size_t	nwords;

	nwords = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		nwords++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (nwords);
}

static size_t	ft_length_word(char const *s, char c)
{
	size_t	length;

	length = 0;
	while (*s && *s != c)
	{
		s++;
		length++;
	}
	return (length);
}

void	ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs);
		i++;
	}
	free(strs);
}

char	**ft_split(char *s, char c)
{
	char	**strings;
	size_t	nwords;
	size_t	lwords;
	size_t	i;

	nwords = ft_num_words(s, c);
	strings = (char **)malloc(sizeof(char *) * (nwords + 1));
	if (!strings)
		return (NULL);
	i = 0;
	while (i < nwords)
	{
		while (*s && *s == c)
			s++;
		lwords = ft_length_word(s, c);
		strings[i] = ft_strndup(s, lwords);
		if (!strings[i])
			ft_free(strings);
		s += lwords;
		i++;
	}
	strings[nwords] = 0;
	return (strings);
}
