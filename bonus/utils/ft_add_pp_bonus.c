/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_pp_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:07:30 by paescano          #+#    #+#             */
/*   Updated: 2023/10/26 12:07:37 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

char	**ft_add_pp(char *arg, char **strs)
{
	char	**tmp;
	int		i;
	int		len;

	i = 0;
	len = ft_pplen(strs) + 1;
	tmp = (char **)malloc(sizeof(char *) * (len + 1));
	if (!tmp)
		ft_free_error(ERROR_MALLOC);
	tmp[len] = NULL;
	while (i < len - 1)
	{
		tmp[i] = strs[i];
		i++;
	}
	tmp[i] = arg;
	if (strs)
		free(strs);
	strs = tmp;
	return (strs);
}
