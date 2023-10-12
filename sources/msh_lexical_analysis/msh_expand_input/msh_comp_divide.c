/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_comp_divide.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:00:27 by jho               #+#    #+#             */
/*   Updated: 2023/10/12 18:11:35 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_comp	*msh_comp_divide(char *input)
{
	int		range[2];
	t_comp	*comps;
	int		(*validator)(char *, int);

	range[0] = 0;
	range[1] = 0;
	comps = NULL;
	while (*(input + range[1]) != '\0')
	{
		validator = msh_get_validator(*(input + range[1]));
		if (validator != NULL)
		{
			msh_comp_add_node_diff(&comps, input, range[0], range[1]);
			range[0] = range[1];
			range[1] = validator(input, range[0] + 1) + 1;
			if (range[1] == 0)
				return (NULL);
			msh_comp_add_node(&comps, input, range[0], range[1]);
			range[0] = range[1];
		}
		else
			++range[1];
	}
	msh_comp_add_node_diff(&comps, input, range[0], range[1]);
	return (comps);
}
