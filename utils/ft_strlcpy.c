/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:48:17 by lromero-          #+#    #+#             */
/*   Updated: 2023/09/23 14:59:19 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*end;
	size_t	srcsize;

	if (!dst || !src)
		return (NULL);
	end = dst + dstsize;
	srcsize = 0;
	while (src[srcsize] != '\0' && srcsize < dstsize)
	{
		dst[srcsize] = src[srcsize];
		srcsize++;
	}
	if (srcsize < dstsize)
		dst[srcsize] = '\0';
	else if (dstsize > 0)
		dst[srcsize - 1] = '\0';
	while (src[srcsize] != '\0')
		srcsize++;
	return (srcsize);
}
