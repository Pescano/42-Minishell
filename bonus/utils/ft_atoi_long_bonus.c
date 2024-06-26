/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:08:09 by paescano          #+#    #+#             */
/*   Updated: 2023/10/30 11:18:26 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static long	atoiloop(const char *str, int pos)
{
	long	num;

	num = 0;
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		if (num > LONG_MAX / 10 || (num == LONG_MAX / 10 && str[pos] - '0' > 7))
			return (-1);
		num = 10 * num + (str[pos] - '0');
		pos++;
	}
	return (num);
}

long	ft_atoi_long(const char *str)
{
	long	res;
	int		sign;
	int		pos;

	sign = 1;
	res = 0;
	pos = 0;
	while (str[pos] == ' ' || (str[pos] <= 13 && str[pos] >= 9))
		pos++;
	if (str[pos] == '-')
	{
		sign = -1;
		pos++;
	}
	else
		if (str[pos] == '+')
			str++;
	res = atoiloop(str, pos);
	if (res == -1)
		return (res);
	return (res * sign);
}
