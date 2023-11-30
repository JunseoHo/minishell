/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:29:19 by jho               #+#    #+#             */
/*   Updated: 2023/11/30 17:13:44 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H
# include "msh_expander.h"
# include "msh_lexer.h"
# include "msh_parser.h"
# include "msh_token.h"
# include "msh_pathfinder.h"
# include "msh_builtin.h"
# include "msh_util.h"
# include "msh_pipeline.h"
# include "msh_executor.h"
# include <dirent.h>
# include <term.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# define UNFORKED 0
# define FORKED 1

int		g_exit_status;



void	do_sigint(int signum);
void	set_terminal_print_off(void);
void	set_terminal_print_on(void);
void	set_default_signal(void);
void	set_signal(void);
void	handle_signal_2(int signo);
#endif
