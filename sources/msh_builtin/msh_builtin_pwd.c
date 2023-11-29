/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_pwd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:54:31 by haekang           #+#    #+#             */
/*   Updated: 2023/11/29 17:28:09 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_builtin.h"

int	msh_builtin_pwd(int *fd, int pipe, char **cmd, t_env *env)
{
	char	*pwd;

	(void)env;
	(void)cmd;
	g_exit_status = 0;
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		printf("getcwd error\n");
		g_exit_status = 1;
		if (pipe == 1)
			exit (g_exit_status);
		return (1);
	}
	write(fd[1], pwd, msh_strlen(pwd));
	write(fd[1], "\n", 2);
	free(pwd);
	if (pipe == 1)
		exit (g_exit_status);
	return (0);
}
