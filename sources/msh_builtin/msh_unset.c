/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:27:11 by haekang           #+#    #+#             */
/*   Updated: 2023/10/14 19:59:43 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	msh_del_node(t_env *node)
{
	free(node->key);
	free(node->value);
	node->next->prev = node->prev;
	node->prev->next = node->next;
	free(node);
}

void	msh_unset(t_env *env, char *key)
{
	t_env	*node;

	node = env;
	while (1)
	{
		if (node->next == NULL)
		{
			if (msh_strcmp(node->key, key) == 0)
				msh_del_node(node);
			break ;
		}
		else
		{
			if (msh_strcmp(node->key, key) == 0)
				msh_del_node(node);
		}
		node = node->next;
	}
}
