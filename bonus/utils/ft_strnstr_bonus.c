/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:44:14 by paescano          #+#    #+#             */
/*   Updated: 2023/10/26 12:06:52 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	x;
	size_t	y;

	if (*s2 == '\0' || s2 == NULL)
		return ((char *)s1);
	x = 0;
	while (s1[x] && x < n)
	{
		y = 0;
		while (s1[x + y] == s2[y] && x + y < n)
		{
			if (s2[y + 1] == '\0')
				return ((char *)s1 + x);
			y++;
		}
		x++;
	}
	return (NULL);
}
