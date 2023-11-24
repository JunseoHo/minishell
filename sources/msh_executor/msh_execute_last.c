/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:25:16 by jho               #+#    #+#             */
/*   Updated: 2023/11/24 13:51:27 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"

int	msh_execute_last_builtin(t_pipeline *pl, int *fd, t_env *env)
{
	int	result;

	if (fd[1] != 1 && close(fd[1]) == -1)
		return (0);
	fd[1] = 1;
	param = msh_token_filter_sym(pl->tokens, WORD);
	if (!msh_execute_redir(pl->tokens, fd))
		return (0);
	if (param == NULL)
		return (0);
	result = msh_execute_builtin(fd[0], fd[1], param, env);
	close(fd[0]);
	close(fd[1]);
	return (result);
}

int	msh_execute_last(t_pipeline *pl, int *fd, t_env *env)
{
	pid_t	pid;
	char	**param;

	if (msh_execute_check_builtin(pl))
		return (msh_execute_last_builtin(pl, fd, env));
	pid = fork();
	if (pid == -1)
		return (0);
	else if (pid == 0)
	{
		if (fd[1] != 1 && close(fd[1]) == -1)
			exit(errno);
		fd[1] = 1;
		param = msh_token_filter_sym(pl->tokens, WORD);
		if (!msh_execute_redir(pl->tokens, fd))
			exit(errno);
		if (param == NULL)
			exit(errno);
		msh_execute_pipeline(fd[0], fd[1], param, env);
	}
	close(fd[0]);
	close(fd[1]);
	return (1);
}
