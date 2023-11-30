/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:07:51 by haekang           #+#    #+#             */
/*   Updated: 2023/11/29 20:53:51 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_builtin.h"

int	msh_builtin_env(int *fd, int pipe, char **cmd, t_env *env)
{
	t_env	*node;

	(void)cmd;
	node = env;
	while (node != NULL)
	{
		if (node->value != NULL)
		{
			write(fd[1], node->key, msh_strlen(node->key));
			write(fd[1], "=", 2);
			write(fd[1], node->value, msh_strlen(node->value));
			write(fd[1], "\n", 2);
		}
		node = node->next;
	}
	g_exit_status = 0;
	if (pipe == 1)
		exit(g_exit_status);
	return (0);
}
