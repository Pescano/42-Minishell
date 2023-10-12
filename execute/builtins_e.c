/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:15:54 by lromero-          #+#    #+#             */
/*   Updated: 2023/10/05 12:24:20 by lromero-         ###   ########.fr       */
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

void	ft_exit(char **n)
{
	int		i;
	int		sign;
	long	num;

	i = is_number(*n);
	if (!i)
	{
		return ;
		//return error & exit 255
	}
	else if (n[1])
	{
		return ;
		//return error 1
	}
	num = ft_atoi_long(*n);
	if (num == -1 && ft_strcmp("-1", n[0] + i - 2))
	{
		return ;
		//return error 1
	}
	sign = 1;
	if (num < 0)
		sign = -1;
	while (num < 0 || num > 255)
		num -= 256 * sign;
	//return (int) num
}
