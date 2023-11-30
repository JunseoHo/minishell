/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:03:25 by jho               #+#    #+#             */
/*   Updated: 2023/11/30 17:49:03 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"
#include <string.h>
#include <errno.h>

void	msh_signal_int(int num)
{
	num = 0;
}

int	main(int argc, char *argv[], char *envp[])
{
	char		*input;
	t_env		*env;
	char		*expanded;
	t_pipeline	*pipelines;

	(void) argc;
	(void) argv;
	signal(SIGINT, msh_signal_int);
	env = msh_env_new_list(envp);
	while (1)
	{
		input = readline("msh$> ");
		if (input == NULL)
		{
			set_terminal_print_on();
			exit (g_exit_status);//여기서 ctrl + d 처리
		}
		expanded = msh_expand(input, env);
		pipelines = msh_lex(expanded);
		if (pipelines == NULL)
		{
			printf("Lex error\n");
			free(input);
			free(expanded);
			continue ;
		}
		msh_execute(pipelines, env);
		msh_pipeline_free_list(pipelines);
		free(expanded);
		free(input);
		system("leaks minishell | grep leaked");
	}
	return (0);
}
