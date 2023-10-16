/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:03:25 by jho               #+#    #+#             */
/*   Updated: 2023/10/16 22:15:27 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	leaks(void)
{
	system("leaks minishell");
}

int	main(int argc, char *argv[], char *envp[])
{
	atexit(leaks);
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
	// char **cmd;
	// cmd = malloc(sizeof(char *) * 4);
	// cmd[0] = "echo";
	// cmd[1] = "fuck";
	// cmd[2] = "you";
	// cmd[3] = "man";
	// msh_echo(cmd);
	// free(cmd);
	// exit(0);
	while (1)
	{
		input = readline("msh$> ");
		tokens = msh_lexical_analysis(input, env);
		free(input);
		exit(0);
	}
	return (0);
}
