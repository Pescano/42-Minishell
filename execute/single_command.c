/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:10:27 by lromero-          #+#    #+#             */
/*   Updated: 2023/10/16 12:31:55 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	heredoc(char **end)
{
	int		fd;
	char	*line;

	fd = open("tmp.txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		return (-1);
	while (1 && end[0] && end[1])
	{
		if (ft_putstr("heredoc> "))
			return (-1);
		line = get_next_line(0);
		if (line && ft_strcmp(line, *end) == 10
			&& ft_strlen(line) == ft_strlen(*end) + 1)
		{
			free(line);
			end++;
		}
		free(line);
		line = NULL;
	}
	while (1)
	{
		if (ft_putstr("heredoc> "))
			return (-1);
		line = get_next_line(0);
		if (line && ft_strcmp(line, *end) == 10
			&& ft_strlen(line) == ft_strlen(*end) + 1)
		{
			free(line);
			break ;
		}
		if (line && ft_putstr_fd(line, fd))
			return (free(line), -1);
		free(line);
		line = NULL;
	}
	close(fd);
	fd = open("tmp.txt", O_RDONLY);
	return (fd);
}
