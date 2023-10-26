/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_e_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:06:37 by paescano          #+#    #+#             */
/*   Updated: 2023/10/25 18:06:45 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

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

int	ft_exit(char **n)
{
	int		i;
	long	num;

	if (!*n)
		ft_finish(0);
	i = is_number(*n);
	if (!i)
		return (ft_print_error(ERROR_EXIT2, *n), ft_finish(255), 255);
	num = ft_atoi_long(*n);
	if (num == -1 && ft_strcmp("-1", n[0] + i - 2))
	{
		ft_print_error("exit : ", NULL);
		ft_print_error(ERROR_EXIT2, *n);
		ft_finish(255);
	}
	else if (n[1])
		return (ft_print_error(ERROR_EXIT1, NULL), 1);
	i = 1;
	if (num < 0)
		i = -1;
	while (num < 0 || num > 255)
		num -= 256 * i;
	return (ft_finish(num), num);
}
