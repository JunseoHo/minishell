/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expand_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:13:49 by jho               #+#    #+#             */
/*   Updated: 2023/10/09 18:32:25 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
/*
size_t	msh_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len) != '\0')
		++len;
	return (len);
}

char	*msh_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (*(src + index) != '\0')
		*(dest + index) = *(src + index);
	*(dest + index) = '\0';
	return (dest);
}

char	*msh_append_char(char *s, char c)
{
	size_t	len;
	char	*result;

	len = msh_strlen(s);
	result = malloc(len + 2);
	if (result == NULL)
		return (NULL);
	msh_strcpy(result, s);
	*(result + len) = c;
	*(result + len + 1) = '\0';
	free(s);
	return (result);
}
*/

typedef struct	s_comp
{
	char			*value;
	struct	s_comp	*next;
}	t_comp;

char	*msh_strncpy(char *dest, char *src, size_t n)
{
	int	index;

	index = 0;
	while (*(src + index) != '\0' && index < n)
	{
		*(dest + index) = *(src + index);
		++index;
	}
	*(dest + index) = '\0';
	return (dest);
}

int	msh_is_sqoute(int c)
{
	return (c == '\'');
}

int	msh_is_dqoute(int c)
{
	return (c == '\"');
}

int	msh_is_dollar(int c)
{
	return (c == '$');
}

t_comp	*msh_last_comp(t_comp *comps)
{
	if (comps == 0)
		return (0);
	while (comps->next != NULL)
		comps = comps->next;
	return (comps);
}

int	msh_add_comp(t_comp **origin, char *input, int begin, int end)
{
	char	*value;
	t_comp	*comp;
	t_comp	*comps;

	value = malloc(end - begin + 1);
	msh_strncpy(value, input + begin, end - begin);
	*(value + end - begin) = '\0';
	comp = malloc(sizeof(t_comp));
	comp->value = value;
	comp->next = 0;
	if (*origin == 0)
		*origin = comp;
	else
	{
		comps = msh_last_comp(*origin);
		comps->next = comp;
	}
	return (1);
}

int	msh_stack_sqoute(char *input, int index);

int	msh_stack_dqoute(char *input, int index)
{
	while (!msh_is_dqoute(*(input + index)))
	{
		if (msh_is_sqoute(*(input + index)))
			index = msh_stack_sqoute(input, index + 1) + 1;
		else
			++index;
	}
	return (index);
}

int	msh_stack_sqoute(char *input, int index)
{
	while (!msh_is_sqoute(*(input + index)))
	{
		if (msh_is_dqoute(*(input + index)))
			index = msh_stack_dqoute(input, index + 1) + 1;
		else
			++index;
	}
	return (index);
}

t_comp	*msh_divide_comps(char *input)
{
	int		left;
	int		right;
	t_comp	*comps;
	
	left = 0;
	right = 0;
	while (*(input + right) != '\0')
	{
		if (msh_is_sqoute(*(input + right)))
		{
			if (left != right)
				msh_add_comp(&comps, input, left, right);
			left = right;
			right = msh_stack_sqoute(input, left + 1) + 1;
			msh_add_comp(&comps, input, left, right);
			left = right;
		}
		else if (msh_is_dqoute(*(input + right)))
		{
			if (left != right)
				msh_add_comp(&comps, input, left, right);
			left = right;
			right = msh_stack_dqoute(input, left + 1) + 1;
			msh_add_comp(&comps, input, left, right);
			left = right;
		}
		else
			++right;
	}
	if (left != right)
		msh_add_comp(&comps, input, left, right);
	return (comps);
}

char	*msh_expand_input(char *input)
{
	t_comp	*comps;
	char	*result;

	comps = msh_divide_comps(input);
	while (comps != 0)
	{
		printf("%s\n", comps->value);
		comps = comps->next;
	}
	//msh_expand_components(components);
	//result = msh_combine_components(components);
	return (result);
}

int	main(int ac, char *av[])
{
	// a'"b''c'
	// a'b"k'"''c'
	// 'a"b"c'
	// 'a"b"c' "d'ac'"
	msh_expand_input("\'a\"b\"c\'\"d\'ac\'\"");
	return (0);
}
