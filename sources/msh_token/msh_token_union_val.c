/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_union_val.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:11:24 by jho               #+#    #+#             */
/*   Updated: 2023/10/27 20:42:53 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_token.h"
#include "../../includes/msh_util.h"

char	*msh_token_union_val(t_token *token)
{
	int		len;
	char	*unioned;

	if (token == NULL)
		return (NULL);
	len = msh_token_len_val(token);
	if (len == -1)
		return (NULL);
	unioned = malloc(sizeof(char) * (len + 1));
	if (unioned == NULL)
		return (NULL);
	len = 0;
	while (token != NULL)
	{
		msh_strcpy(unioned + len, token->val);
		len += msh_strlen(token->val);
		token = token->next;
	}
	*(unioned + len) = '\0';
	return (unioned);
}