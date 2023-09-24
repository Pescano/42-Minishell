/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:33:06 by lromero-          #+#    #+#             */
/*   Updated: 2023/09/22 17:32:54 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size1;
	size_t	size2;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	res = malloc (size1 + size2 + 1);
	if (!res)
		return (NULL);
	*res = '\0';
	ft_strlcpy(res, s1, size1 + 1);
	ft_strlcat(res, s2, size1 + size2 + 1);
	return (res);
}

