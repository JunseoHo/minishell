/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:03:25 by jho               #+#    #+#             */
/*   Updated: 2023/10/19 23:54:01 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	leaks(void)
{
	system("leaks minishell | grep leaked");
}

int	main(int argc, char *argv[], char *envp[])
{
	atexit(leaks);
	t_env	*env;
	// char	*input;
	// t_token	*tokens;

	(void) argc;
	(void) argv;
	env = msh_env_new_list(envp);
	if (env == NULL)
	{
		write(2, "msh : failed to read environment.\n", 34);
		return (1);
	}
	// msh_unset(env, "9awefce");
	// msh_env(env);
	// msh_pwd();
	char *arr[2];
	arr[0] = "cd";
	arr[1] = "";//세그뜸
	msh_env(env);
	printf("\n\n\n\n");
	msh_cd(arr, env);
	msh_env(env);
	exit(0);
	// while (1)
	// {
	// 	input = readline("msh$> ");
	// 	tokens = msh_lexical_analysis(input, env);
	// 	free(input);
	// 	exit(0);
	// }
	return (0);
}
