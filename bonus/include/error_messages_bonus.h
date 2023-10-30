/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:04:46 by paescano          #+#    #+#             */
/*   Updated: 2023/10/30 17:07:15 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_BONUS_H
# define ERROR_MESSAGES_BONUS_H

# define ERROR_MALLOC "\033[31mError\nMalloc failed\033[0m\n"
# define ERROR_QUOTES "Syntax error, unclosed quotes\n"
# define ERROR_PIPES "minishell: syntax error pipe\n"
# define ERROR_REDIR "minishell: syntax error redirection\n"
# define ERROR_CWD "\033[31mError\nGetcwd failed\033[0m\n"
# define ERROR_EXIT1 "exit: too many arguments\n"
# define ERROR_EXIT2 ": numeric argument required\n"
# define ERROR_FILE ": No such file or directory\n"
# define ERROR_FORK "\033[31mError\nfork failed\033[0m\n"
# define ERROR_WRITE "\033[31mError\nwrite failed\033[0m\n"
# define ERROR_ECVE ": command not found\n"
# define ERROR_PIPE "\033[31mError\npipe failed\033[0m\n"
# define ERROR_AST "minishell : ambiguous redirect\n"
# define ERROR_CD " not set\n"

#endif