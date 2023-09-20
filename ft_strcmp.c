/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:29:04 by paescano          #+#    #+#             */
/*   Updated: 2023/09/20 13:30:04 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	pos;

	pos = 0;
	while (s1[pos] == s2[pos] && s1[pos] != '\0')
		pos++;
	return ((unsigned char)s1[pos] - (unsigned char)s2[pos]);
}
