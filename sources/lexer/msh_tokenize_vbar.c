/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_tokenize_vbar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:44:51 by jho               #+#    #+#             */
/*   Updated: 2023/08/29 21:02:13 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	msh_tokenize_vbar(t_token **tokens, char *str)
{
	t_token	*token;
	char	*value;

	if (*(str + 1) == '|')
		value = msh_substr(str, 0, 2);
	else
		value = msh_substr(str, 0, 1);
	if (value == 0)
		return (-1);
	token = malloc(sizeof(t_token));
	if (token == 0)
	{
		free(value);
		return (-1);
	}
	if (*(str + 1) == '|')
		token->symbol = OR_IF;
	else
		token->symbol = PIPE;
	token->value = value;
	token->next = 0;
	msh_append_token(tokens, token);
	return (msh_strlen(value));
}
