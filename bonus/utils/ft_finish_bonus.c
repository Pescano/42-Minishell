/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:11:46 by paescano          #+#    #+#             */
/*   Updated: 2023/10/26 12:11:52 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_finish(int i)
{
	ft_free_all();
	if (g_global.cmd_splitted)
		ft_freevpp((void **)g_global.cmd_splitted);
	if (g_global.cmd)
		ft_free_cmd();
	if (!access("tmp.txt", F_OK))
		unlink("tmp.txt");
	ft_reset_fds();
	exit(i);
}
