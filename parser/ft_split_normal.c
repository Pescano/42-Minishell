/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:14:46 by paescano          #+#    #+#             */
/*   Updated: 2023/09/28 18:22:38 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	wordlen_perso(char *prompt, int i)
{
	int	len;

	len = 0;
	while (prompt[i] && prompt[i] != ' ' && prompt[i] != '<' && prompt[i] != '>'
		&& prompt[i] != '|')
	{
		len++;
		i++;
	}
	return (len);
}

char	*ft_noq(char *prompt, int i)
{
	char	*aux;
	int		j;
	int		len;

	len = wordlen_perso(prompt, i);
	aux = ft_calloc(len + 2, sizeof(char));
	j = 0;
	while (prompt[i] != ' ' && prompt[i] != '"'
		&& prompt[i] != '\'' && prompt[i] != '\0')
	{
		aux[j] = prompt[i];
		i++;
		j++;
	}
	return (aux);
}

char	*ft_call_noq(char *prompt, int *i)
{
	char	*aux;

	aux = ft_noq(prompt, *i);
	*i += strlen(aux);
	return (aux);
}
