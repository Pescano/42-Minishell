/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:20:57 by paescano          #+#    #+#             */
/*   Updated: 2023/10/26 12:21:02 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	pos;

	pos = 0;
	while (s1[pos] == s2[pos] && s1[pos] != '\0')
		pos++;
	return ((unsigned char)s1[pos] - (unsigned char)s2[pos]);
}
