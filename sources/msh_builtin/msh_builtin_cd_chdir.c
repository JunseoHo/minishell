/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_cd_chdir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:14:44 by haekang           #+#    #+#             */
/*   Updated: 2023/11/29 20:53:30 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_builtin.h"

int	msh_builtin_cd_chdir(char *path, char *old_pwd, int pipe)
{
	if (chdir(path))
	{
		free(old_pwd);
		printf("minishell: cd: %s: No such file or directory\n", path);
		g_exit_status = 1;
		if (pipe == 1)
			exit(g_exit_status);
		return (0);
	}
	return (1);
}
