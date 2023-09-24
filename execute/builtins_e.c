/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:15:54 by lromero-          #+#    #+#             */
/*   Updated: 2023/09/22 18:21:13 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char **args)
{
	int	nl;

	if (!args)
		return ;
	nl = 0;
	if (!ft_strcmp(*args, "-n"))
	{
		nl = 1;
		args++;
	}
	while (*args)
	{
		printf("%s", *args);
		args++;
		if (*args)
			printf(" ");
	}
	if (!nl)
		printf("\n");
}

void	ft_exit(char *n)
{}
