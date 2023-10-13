/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:25:38 by lromero-          #+#    #+#             */
/*   Updated: 2023/10/12 18:30:52 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	if (write(fd, s, len) < 0)
		return (1);
	return (0);
}

static void	heredoc_loop(char *end, int fd)
{
	char	*line;

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
		{
			free(line);
			return ;
		}
		free(line);
		line = NULL;
	}
}

int	ft_heredoc(char **end)
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
			end++;
		free(line);
		line = NULL;
	}
	heredoc_loop(*end, fd);
	close(fd);
	fd = open("tmp.txt", O_RDONLY);
	return (fd);
}
