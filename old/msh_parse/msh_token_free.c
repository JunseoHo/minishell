/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:32:45 by jho               #+#    #+#             */
/*   Updated: 2023/10/26 08:38:37 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*msh_token_free(t_token *token)
{
	t_token *child;

	if (token == NULL)
		return (NULL);
	if (token->value != NULL)
		free(token->value);
	child = token->child;
	while (child != NULL)
	{
		msh_token_free(token->child);
		child = child->next;
	}
	return (NULL);
}
