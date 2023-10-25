/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:57:26 by lromero-          #+#    #+#             */
/*   Updated: 2023/10/25 10:58:22 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_closep(int *p, int n)
{
	if (n % 2 == 0)
		close(p[0]);
	else if (n > 0)
		close(p[1]);
}