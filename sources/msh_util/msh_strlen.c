/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_strlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:31:32 by jho               #+#    #+#             */
/*   Updated: 2023/10/26 14:59:07 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	msh_strlen(char *s)
{
	int	len;

	len = 0;
	while (*(s + len) != '\0')
		++len;
	return (len);
}