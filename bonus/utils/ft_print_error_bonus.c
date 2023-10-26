/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:15:59 by paescano          #+#    #+#             */
/*   Updated: 2023/10/26 12:16:04 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_print_error(char *error, char *str)
{
	int	fd;

	fd = dup(STDOUT_FILENO);
	dup2(STDERR_FILENO, STDOUT_FILENO);
	if (!str)
		printf("%s", error);
	else
		printf("%s%s", str, error);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}
