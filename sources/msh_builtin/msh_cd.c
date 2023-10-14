/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:12:33 by haekang           #+#    #+#             */
/*   Updated: 2023/10/14 22:14:21 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	msh_pwd_oldpwd(t_env *env)
{
	t_env	*pwd;
	t_env	*old_pwd;

	pwd = msh_env_get_node(env, "PWD");
	old_pwd = msh_env_get_node(env, "OLDPWD");
	free(old_pwd->value);
	old_pwd->value = pwd->value;
	pwd->value = getcwd(NULL, 0);
	if (pwd->value == NULL)
		printf("getcwd error\n");
}

static void	msh_cd_home(t_env *env)
{
	char	*path;

	path = msh_env_get_value(env, "HOME");
	if (chdir(path))
	{
		printf("chdir error\n");
		return ;
	}
	msh_pwd_oldpwd(env);
}

static void	msh_cd_env(t_env *env, char *key)
{
	char	*path;

	path = msh_env_get_value(env, key);
	if (chdir(path))
	{
		printf("chdir error\n");
		return ;
	}
	msh_pwd_oldpwd(env);
}

void	msh_cd(char **cmd, t_env *env)
{
	char	*path;

	if (msh_strcmp(cmd[1], "~") == 0 || cmd[1] == NULL)
		msh_cd_home(env);
	else if (cmd[1][0] == '$')
		msh_cd_env(env, &(cmd[1][1]));
	else
	{
		path = cmd[1];
		if (chdir(path))
		{
			printf("chdir error\n");
			return ;
		}
		msh_pwd_oldpwd(env);
	}
}
