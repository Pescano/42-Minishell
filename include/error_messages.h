/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:21:26 by paescano          #+#    #+#             */
/*   Updated: 2023/10/13 11:22:44 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H

# define ERROR_MALLOC "\033[31mError\nMalloc failed\033[0m\n"
# define ERROR_QUOTES "Syntax error, unclosed quotes\n"
# define ERROR_PIPES "minishell: syntax error pipe\n"
# define ERROR_REDIR "minishell: syntax error redirection\n"
# define ERROR_CWD "\033[31mError\nGetcwd failed\033[0m\n"
# define ERROR_EXIT1 "exit: too many arguments\n"
# define ERROR_EXIT2 "exit: %s: numeric argument required\n"
# define ERROR_FILE "%s: No such file or directory\n"

#endif