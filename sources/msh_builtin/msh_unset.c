/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeseong <haeseong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:27:11 by haekang           #+#    #+#             */
/*   Updated: 2023/10/18 17:49:18 by haeseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	msh_del_node(t_env *node)
{
	t_env	*tmp;

	free(node->key);
	free(node->value);
	if (node->prev == NULL)
	{
		node->key = node->next->key;
		node->value = node->next->value;
		tmp = node->next;
		node->next = node->next->next;
		free(tmp);
	}
	else if (node->next == NULL)
	{
		node->prev->next = NULL;
		free(node);
	}
	else
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
		free(node);
	}
}

void	msh_unset(t_env *env, char *key)
{
	t_env	*node;

	node = env;
	if (key[0] <= '9' && key[0] >= '0')
	{
		printf("minishell: unset: '%s': not a valid identifier\n", key);
		return ;
	}
	while (node != NULL)
	{
		if (msh_strcmp(node->key, key) == 0)
			msh_del_node(node);
		node = node->next;
	}
}
//명령어 반환값 처리 해줘야함