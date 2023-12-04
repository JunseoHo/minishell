/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lex_tokenize_qoutes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 08:49:45 by jho               #+#    #+#             */
/*   Updated: 2023/12/04 15:02:42 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_lexer.h"

int	msh_lex_tokenize_qoutes(t_token **sym_table, char *s)
{
	int		idx;
	t_token	*token;

	idx = 1;
	while (*(s + idx) != *s)
		++idx;
	++idx;
	while (!msh_is_charset(*(s + idx), "&|<>() ") && *(s + idx) != '\0')
		++idx;
	token = msh_token_malloc_sym(WORD);
	if (token == NULL)
		return (0);
	// token->val = msh_substr(s, 0, idx);
	token->val = msh_substr(s, 1, idx - 1);
	if (token->val == NULL)
	{
		msh_token_free(token);
		return (0);
	}
	msh_token_add_next(sym_table, token);
	return (idx);
}
