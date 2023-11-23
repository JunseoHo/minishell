/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pathfind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:44:27 by jho               #+#    #+#             */
/*   Updated: 2023/11/03 17:24:30 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_pathfinder.h"

char	*msh_pathfind(char *cmd, t_env *env)
{
	char	**path;
	char	*cmd_path;

	path = msh_find_env_path(env);
	if (path == NULL)
		return (NULL);
	cmd_path = msh_find_cmd_abspath(path, cmd);
	if (cmd_path == NULL)
		return (NULL);
	return (cmd_path);
}