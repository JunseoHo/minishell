/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeseong <haeseong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:12:33 by haekang           #+#    #+#             */
/*   Updated: 2023/10/18 18:07:47 by haeseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	msh_pwd_oldpwd(t_env *env)
{
	t_env	*pwd;
	t_env	*old_pwd;
	char	*cur_path;

	printf("어디고\n");
	pwd = msh_env_get_node(env, "PWD");
	old_pwd = msh_env_get_node(env, "OLDPWD");
	cur_path = getcwd(NULL, 0);
	if (cur_path == NULL)
	{
		printf("getcwd error\n");
		return ;
	}
	free(old_pwd->value);
	old_pwd->value = pwd->value;
	pwd->value = cur_path;
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
		msh_cd_env(env, "HOME");
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
//없는 경로가 들어올 경우 에러 처리 해줘야함, 명령어 반환값 구현해야함
//환경변수에 홈 삭제됐을때 에러처리 해야함