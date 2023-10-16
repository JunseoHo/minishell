/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:19:33 by haekang           #+#    #+#             */
/*   Updated: 2023/10/16 22:11:05 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	msh_get_start_idx(char **cmd, int *start_idx, int i)
{
	int	j;

	while (cmd[i] != NULL)
	{
		if (cmd[i][0] == '-' && cmd[i][1] == 'n')
		{
			j = 2;
			while (cmd[i][j] == 'n')
				j++;
			if (cmd[i][j] != '\0')
			{
				*start_idx = i;
				break ;
			}
		}
		else
		{
			*start_idx = i;
			break ;
		}
		i++;
	}
	if (cmd[i] == NULL)
		*start_idx = i;
}

static void	msh_check_option(char **cmd, int *n_flag)
{
	int	i;
	int	j;

	i = 1;
	while (cmd[i] != NULL)
	{
		if (cmd[i][0] == '-' && cmd[i][1] == 'n')
		{
			j = 2;
			while (cmd[i][j] == 'n')
				j++;
			if (cmd[i][j] == '\0')
				*n_flag = 1;
		}
		i++;
	}
	return ;
}

void	msh_echo(char **cmd)
{
	int		n_flag;
	int		start_idx;
	int		i;

	i = 1;
	n_flag = 0;
	start_idx = 1;
	msh_check_option(cmd, &n_flag);
	msh_get_start_idx(cmd, &start_idx, 1);
	while (cmd[start_idx] != NULL)
	{
		printf("%s", cmd[start_idx]);
		if (cmd[++start_idx] != NULL)
			printf(" ");
	}
	if (n_flag == 0)
		printf("\n");
}

// static void	msh_check_echo_options(char **cmd, int *n_flag, int *start_idx)
// {
// 	int	i;
// 	int	j;

// 	i = 1;
// 	while (cmd[i] != NULL)
// 	{
// 		j = 2;
// 		if (cmd[i][0] == '-' && cmd[i][1] == 'n')
// 		{
// 			while (cmd[i][j] == 'n')
// 				j++;
// 			if (cmd[i][j] == '\0')
// 				*n_flag = 1;
// 			else if (cmd[i][j] != '\0')
// 			{
// 				*start_idx = i;
// 				break ;
// 			}
// 		}
// 		else
// 		{
// 			*start_idx = i;
// 			break ;
// 		}
// 		i++;
// 	}
// 	if (cmd[i] == NULL)
// 		*start_idx = i;
// }