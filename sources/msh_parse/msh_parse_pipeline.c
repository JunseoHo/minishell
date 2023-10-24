/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse_pipeline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:57:44 by jho               #+#    #+#             */
/*   Updated: 2023/10/24 14:33:05 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	msh_parse_pipeline(t_token *root, t_token **tokens)
{
	t_token	*token;

	token = msh_new_token_by_sym(COMMAND);
	msh_add_child(root, token);
	msh_parse_command(token, tokens);
	while (msh_accept(PIPE, *tokens))
	{
		token = msh_dequeue(tokens);
		msh_add_child(root, token);
		token = msh_new_token_by_sym(PIPELINE);
		if (token == NULL)
			return (0);
		msh_add_child(root, token);
		msh_parse_pipeline(token, tokens);
	}
	return (1);
}
