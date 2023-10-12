/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:03:25 by jho               #+#    #+#             */
/*   Updated: 2023/10/12 16:06:26 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_env	*env;
	char	*input;
	t_token	*tokens;

	argc = 0;
	argv = 0;
	input = 0;
	tokens = 0;
	env = msh_env_new_list(envp);
	while (env != NULL)
	{
		printf("%s -> %s\n", env->key, env->value);
		env = env->next;
	}
	/*
	while (1)
	{
		input = readline("msh$> ");
		tokens = msh_lexical_analysis(input);
		free(input);
	}
	*/
	return (0);
}
