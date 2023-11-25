/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_export_print.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:10:18 by haekang           #+#    #+#             */
/*   Updated: 2023/11/25 05:00:34 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_builtin.h"

void	msh_print_key_value(int out, char *key, char *value)
{
	write(out, "declare -x ", msh_strlen("declare -x "));
	write(out, key, msh_strlen(key));
	write(out, "=", 2);
	write(out, "\"", 2);
	write(out, value, msh_strlen(value));
	write(out, "\"", 2);
	write(out, "\n", 2);
}

int	msh_export_print(t_env *env, int out)
{
	t_env	*node;

	node = env;
	while (node != NULL)
	{
		if (node->value == NULL)
		{
			write(out, "declare -x ", msh_strlen("declare -x "));
			write(out, node->key, msh_strlen(node->key));
			write(out, "\n", 2);
		}
		else if (!msh_strcmp(node->key, "_"))
		{
			node = node->next;
			continue ;
		}
		else
			msh_print_key_value(out, node->key, node->value);
		node = node->next;
	}
	g_exit_status = 0;
	return (1);
}
