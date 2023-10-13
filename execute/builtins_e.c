/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:15:54 by lromero-          #+#    #+#             */
/*   Updated: 2023/10/13 16:32:59 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **args)
{
	int	nl;

	nl = 0;
	if (*args && !ft_strcmp(*args, "-n"))
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
	return (0);
}

static int	is_number(char *n)
{
	int	i;

	i = 0;
	while (n[i] == ' ' || (n[i] <= 13 && n[i] >= 9))
		i++;
	if (n[i] == '-' || n[i] == '+')
		i++;
	while (n[i] >= '0' && n[i] <= '9')
		i++;
	if (n[i])
		return (0);
	return (i);
}

static void ft_finish(int i)
{
	ft_free_all();
	if (g_global.cmd_splitted)
		ft_freevpp((void **)g_global.cmd_splitted);
	if (g_global.cmd)
		ft_free_cmd();
	if (!access("tmp.txt", F_OK))
		unlink("tmp.txt");
	exit(i);
}

int	ft_exit(char **n)
{
	int		i;
	long	num;

	if (!*n)
		ft_finish(0);
	i = is_number(*n);
	if (!i)
		ft_finish(255);
	else if (n[1])
	{
		printf(ERROR_EXIT1);
		return (1);
	}
	num = ft_atoi_long(*n);
	if (num == -1 && ft_strcmp("-1", n[0] + i - 2))
	{
		printf(ERROR_EXIT2, *n);
		return (1);
	}
	i = 1;
	if (num < 0)
		i = -1;
	while (num < 0 || num > 255)
		num -= 256 * i;
	ft_finish(num);
}
