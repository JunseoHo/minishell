/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_pipe_shift.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:23:35 by jho               #+#    #+#             */
/*   Updated: 2023/11/30 15:45:42 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"

int	msh_execute_pipe_shift(int *fd, int *local_fd)
{
	if (fd[0] != local_fd[0])
		close(local_fd[0]);
	if (fd[1] != local_fd[1])
		close(local_fd[1]);
	close(fd[0]);
	close(fd[1]);
	fd[0] = fd[2];
	fd[1] = fd[3];
	return (1);
}
