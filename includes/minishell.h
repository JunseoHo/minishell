/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:02:22 by jho               #+#    #+#             */
/*   Updated: 2023/10/14 21:24:00 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
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

typedef enum e_symbol
{
	WORD,
	ASSIGNMENT_WORD,
	REDIRECTION,
	PIPE,
	AND_IF,
	OR_IF,
	L_BRACKET,
	R_BRACKET,
	EQUAL_SIGN,
	SIMPLE_COMMAND_ELEMENT,
	SIMPLE_COMMAND,
	COMMAND,
	PILELINE,
	SUBSHELL,
	LIST,
	ROOT
}	t_symbol;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

typedef struct s_comp
{
	char			*value;
	struct s_comp	*next;
}	t_comp;

typedef struct s_token
{
	t_symbol		symbol;
	char			*value;
	struct s_token	*next;
}	t_token;

typedef struct s_tree
{
	t_symbol		symbol;
	char			*value;
	struct s_tree	*children;
}	t_tree;

// env
t_env	*msh_env_new_list(char *envp[]);
t_env	*msh_env_free_list(t_env *list);
t_env	*msh_env_new_node(void);
t_env	*msh_env_free_node(t_env *node);
int		msh_env_add_node(t_env **list, char *envp);
t_env	*msh_env_last_node(t_env *list);
char	*msh_env_parse_key(char *envp);
char	*msh_env_parse_value(char *envp);
char	*msh_env_get_value(t_env *env, char *key);
t_env	*msh_env_get_node(t_env *env, char *key);
// builtin
void	msh_env(t_env *env);
void	msh_unset(t_env *env, char *key);
void	msh_pwd(void);
void	msh_cd(char **cmd, t_env *env);
// lexical analysis
t_token		*msh_lexical_analysis(char *input, t_env *env);
// lexical analysis : expand input
int			msh_comp_add_node(t_comp **origin, char *input, int begin, int end);
void		msh_comp_add_node_diff(t_comp **comps, char *input, int begin, int end);
t_comp		*msh_comp_divide(char *input);
char		*msh_comp_env(char *input, t_env *env);
char		*msh_comp_expand(t_comp *origin, t_env *env);
t_comp		*msh_comp_free(t_comp *comps);
t_comp		*msh_comp_last_node(t_comp *comps);
char		*msh_comp_union(t_comp *origin);
char		*msh_expand_input(char *input, t_env *env);
int			msh_validate_dqoute(char *input, int index);
int			msh_validate_sqoute(char *input, int index);
int			(*msh_get_validator(char c))(char *input, int index);
// utils
int			msh_is_dollar(int c);
int			msh_is_dqoute(int c);
int			msh_is_sqoute(int c);
int			msh_strcmp(char *s1, char *s2);
char		*msh_substr(char *str, int startIdx, int endIdx);
size_t		msh_strlen(char *s);
char		*msh_strncpy(char *dest, char *src, size_t n);
void		msh_strtrim_bothends(char *str);
int			msh_is_special_chr(char c);
#endif
