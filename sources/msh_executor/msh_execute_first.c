/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:24:03 by jho               #+#    #+#             */
/*   Updated: 2023/11/30 17:47:50 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"

int	msh_execute_first_builtin(t_pipeline *pl, int *fd, t_env *env, int forked)
{
	char	**param;

	param = msh_token_filter_sym(pl->tokens, WORD);
	if (param == NULL)
	{
		if (forked == FORKED)
			exit(errno);
		else
			return (-1);
	}
	msh_execute_builtin(fd, param, env, forked);
	msh_execute_free_param(param);
	return (forked);
}

void	msh_execute_first_child(t_pipeline *pl, int *fd, t_env *env, int fk)
{
	char	**param;

	if (msh_execute_check_builtin(pl))
		msh_execute_first_builtin(pl, fd, env, fk);
	else
	{
		param = msh_token_filter_sym(pl->tokens, WORD);
		if (param == NULL)
			exit(errno);
		msh_execute_pipeline(fd[0], fd[1], param, env);
	}
}

int	msh_execute_first(t_pipeline *pl, int *fd, t_env *env, int forked)
{
	int		local_fd[2];
	pid_t	pid;

	local_fd[0] = 0;
	local_fd[1] = fd[1];
	if (msh_execute_redir(pl, local_fd) != 1)
		return (-1);
	if (msh_execute_check_builtin(pl) && !forked)
		return (msh_execute_first_builtin(pl, local_fd, env, forked));
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
    if (fd[0] != 0 && close(fd[0]) == -1)
			return (-1);
		msh_execute_first_child(pl, local_fd, env, forked);
	}
	if (local_fd[0] != 0 && close(local_fd[0]) == -1)
		return (-1);
	if (local_fd[1] != fd[1] && close(local_fd[1]) == -1)
		return (-1);
	return (1);
}
