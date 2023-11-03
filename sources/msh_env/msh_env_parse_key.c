/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_parse_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:07:28 by jho               #+#    #+#             */
/*   Updated: 2023/10/27 20:02:44 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_env.h"

char	*msh_env_parse_key(char *envp)
{
	int		index;
	char	*key;

	index = 0;
	if (!msh_strchr(envp, '='))
		return (NULL);
	while (*(envp + index) != '=')
		++index;
	key = malloc(index + 1);
	if (key == NULL)
		return (NULL);
	msh_strncpy(key, envp, index);
	return (key);
}
