/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:43:47 by paescano          #+#    #+#             */
/*   Updated: 2023/10/26 12:06:48 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;

	x = 0;
	while (x < n)
	{
		if (s1[x] == s2[x] && (s1[x] || s2[x]))
			x++;
		else
			return ((unsigned char)s1[x] - (unsigned char)s2[x]);
	}
	return (0);
}
