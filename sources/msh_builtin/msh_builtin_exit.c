/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:41:04 by haekang           #+#    #+#             */
/*   Updated: 2023/12/06 16:51:22 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

static int	msh_exit_and_print(int exit_code, char *s, int out, int pipe)
{
	if (pipe != 1)
		write (out, "exit\n", 6);
	if (s != NULL)
	{
		write(2, "minishell: exit: ", 17);
		write(2, s, msh_strlen(s));
		write(2, ": numeric argument required\n", 28);
	}
	exit(exit_code);
}

static int	msh_check_overflow(char *str)
{
	const char	*llong_min = "-9223372036854775808";
	const char	*llong_max = "9223372036854775807";
	int			str_len;

	str_len = msh_strlen(str);
	if (str[0] == '-')
	{
		if (str_len >= 20)
		{
			if (str_len > 20 || msh_strcmp(str, (char *)llong_min) > 0)
				return (0);
		}
	}
	else
	{
		if (str_len >= 19)
		{
			if (str_len > 19 || msh_strcmp(str, (char *)llong_max) > 0)
				return (0);
		}
	}
	return (1);
}

static int	msh_num_format_exception(char *str)
{
	if (*str == '\0')
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
			return (0);
	}
	return (1);
}

static long long	msh_atol(char *str)
{
	int			flag;
	long long	result;

	flag = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return (result * flag);
}

int	msh_builtin_exit(int *fd, int pipe, char **cmd, t_env *env)
{
	(void)env;
	fd[1] = 2;
	if (cmd[1] == NULL)
		msh_exit_and_print(g_exit_status, NULL, fd[1], pipe);
	else if (cmd[1] != NULL)
	{
		if (!msh_num_format_exception(cmd[1]))
			msh_exit_and_print(255, cmd[1], fd[1], pipe);
		if (cmd[2] != NULL)
		{
			if (pipe != 1)
				write (fd[1], "exit\n", 6);
			write(2, "minishell: exit: too many arguments\n", 36);
			g_exit_status = 1;
			if (pipe == 1)
				exit(g_exit_status);
			return (1);
		}
		if (!msh_check_overflow(cmd[1]))
			msh_exit_and_print(255, cmd[1], fd[1], pipe);
		else
			msh_exit_and_print((unsigned char)msh_atol(cmd[1]),
				NULL, fd[1], pipe);
	}
	return (0);
}
