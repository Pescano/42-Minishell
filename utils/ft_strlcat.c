/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:06:22 by lromero-          #+#    #+#             */
/*   Updated: 2023/09/23 14:59:30 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	res;
	size_t	aux;

	res = 0;
	aux = 0;
	if (!dst || !src)
		return (NULL);
	while (dst[res] != '\0' && res < dstsize)
		res++;
	if (res == dstsize && dst[res] != '\0')
		return (res + ft_strlen(src));
	while (res + 1 < dstsize && src[aux] != '\0')
	{
		dst[res] = src[aux];
		res++;
		aux++;
	}
	dst[res] = '\0';
	return (ft_strlen(src) + res - aux);
}
