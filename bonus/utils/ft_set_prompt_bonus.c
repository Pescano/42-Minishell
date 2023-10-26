/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_prompt_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:17:55 by paescano          #+#    #+#             */
/*   Updated: 2023/10/26 12:18:00 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

char	*ft_set_prompt(void)
{
	char	*user;
	char	*pwd;
	char	*tmp;

	if (ft_getenv("USER"))
		user = ft_strdup(ft_getenv("USER"));
	else
		user = ft_strdup("null_user");
	if (ft_getenv("PWD"))
		pwd = ft_strdup(ft_getenv("PWD"));
	else
		pwd = ft_strdup("null_pwd");
	tmp = ft_strjoin(pwd, "@");
	tmp = ft_strjoin(tmp, user);
	tmp = ft_strjoin(tmp, "$ ");
	free(user);
	return (tmp);
}
