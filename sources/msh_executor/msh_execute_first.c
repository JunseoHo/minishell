/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:24:03 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 16:50:24 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"
#include "../../includes/msh_signal.h"

int	msh_execute_first_builtin(t_pipeline *pl, int *fd, t_env *env, int forked)
{
	char	**param;

	param = msh_token_filter_sym(pl->tokens, WORD);
	if (param == NULL)
	{
		if (forked == FORKED)
			msh_exit(errno);
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
			msh_exit(errno);
		msh_execute_pipeline(fd[0], fd[1], param, env);
	}
}

int	msh_execute_first(t_pipeline *pl, int *fd, t_env *env, int forked)
{
	int		local_fd[2];

	local_fd[0] = 0;
	local_fd[1] = fd[1];
	if (msh_execute_redir(pl, local_fd, env) != 1)
		return (-1);
	if (msh_execute_check_builtin(pl) && !forked)
		return (msh_execute_first_builtin(pl, local_fd, env, forked));
	pl->pid = fork();
	if (pl->pid == -1)
		msh_exit(errno);
	if (pl->pid == 0)
	{
		msh_set_default_signal();
		if (fd[0] != 0 && close(fd[0]) == -1)
			msh_exit(errno);
		msh_execute_first_child(pl, local_fd, env, forked);
	}
	msh_set_blocking_signal();
	if (local_fd[0] != 0 && close(local_fd[0]) == -1)
		msh_exit(errno);
	if (local_fd[1] != fd[1] && close(local_fd[1]) == -1)
		msh_exit(errno);
	return (1);
}
