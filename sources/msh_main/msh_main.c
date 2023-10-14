/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:03:25 by jho               #+#    #+#             */
/*   Updated: 2023/10/14 22:25:35 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_env	*env;
	char	*input;
	t_token	*tokens;

	(void) argc;
	(void) argv;
	env = msh_env_new_list(envp);
	if (env == NULL)
	{
		write(2, "msh : failed to read environment.\n", 34);
		return (1);
	}
	// char *arr[2];
	// arr[0] = "cd";
	// arr[1] = "..";
	// msh_cd(arr, env);
	// msh_cd(arr, env);
	// printf("\n\n");
	// msh_env(env);
	// printf("\n\n");
	// msh_pwd();
	
	// while (1)
	// {
	// 	input = readline("msh$> ");
	// 	tokens = msh_lexical_analysis(input, env);
	// 	free(input);
	// }
	return (0);
}
