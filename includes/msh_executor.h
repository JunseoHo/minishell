/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_executor.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:00:43 by jho               #+#    #+#             */
/*   Updated: 2023/11/24 13:52:40 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_EXECUTOR_H
# define MSH_EXECUTOR_H
# include <errno.h>
# include <fcntl.h>
# include "msh.h"
# include "msh_token.h"
# include "msh_pipeline.h"
# include "msh_env.h"
# include "msh_pathfinder.h"
# include "msh_builtin.h"

int		msh_execute(t_pipeline *pipelines, t_env *env);
int		msh_execute_builtin(int in, int out, char **param, t_env *env);
int		msh_execute_check_builtin(t_pipeline *pipeline);
int		msh_execute_first(t_pipeline *pl, int *fd, t_env *env);
int		msh_execute_last(t_pipeline *pl, int *fd, t_env *env);
int		msh_execute_middle(t_pipeline *pl, int *fd, t_env *env);
int		msh_execute_pipe_shift(int *fd);
void	msh_execute_pipeline(int in, int out, char **param, t_env *env);
int		msh_execute_redir(t_token *tokens, int *fd);
#endif
