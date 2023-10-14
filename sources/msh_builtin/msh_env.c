/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:07:51 by haekang           #+#    #+#             */
/*   Updated: 2023/10/14 19:12:38 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	msh_env(t_env *env)
{
	t_env	*node;

	node = env;
	while (1)
	{
		if (node->next == NULL)
		{
			if (node->value != NULL)
				printf("%s=%s\n", node->key, node->value);
			break ;
		}
		else
		{
			if (node->value != NULL)
				printf("%s=%s\n", node->key, node->value);
		}
		node = node->next;
	}
}
//export로 '='없이 선언된 변수는 value=NULL로 만들어 구분한다.
//env는 key=value 구조만 출력한다.
//실제 zsh->bash에서도 key=value구조로 선언된 환경변수만을 가져온다.