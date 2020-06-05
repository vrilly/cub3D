/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stringbuilder.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 12:00:00 by tjans         #+#    #+#                 */
/*   Updated: 2020/05/05 12:00:00 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "utils.h"

void			sb_cleanup(t_stringbuilder **root)
{
	t_stringbuilder	*sb_ptr;

	sb_ptr = *root;
	while (*root)
	{
		free(sb_ptr->str);
		*root = sb_ptr->next;
		free(sb_ptr);
		sb_ptr = *root;
	}
}

int				sb_strcpy(char *str, t_stringbuilder *root, int max_len)
{
	int	ret;

	ret = 0;
	while (root && max_len)
	{
		if (root->strlen > max_len)
			root->strlen = max_len;
		ft_memcpy(str, root->str, root->strlen);
		ret += root->strlen;
		str += root->strlen;
		root = root->next;
	}
	return (ret);
}

int				sb_append(t_stringbuilder *root, char *str, int len)
{
	t_stringbuilder	*elem;

	elem = ft_calloc(1, sizeof(t_stringbuilder));
	if (!elem)
		return (0);
	elem->str = str;
	elem->strlen = len;
	while (root->next)
		root = root->next;
	root->next = elem;
	return (1);
}

t_stringbuilder	*sb_create(char *str, int len)
{
	t_stringbuilder	*root;

	root = ft_calloc(1, sizeof(t_stringbuilder));
	if (!root)
		return (NULL);
	root->str = str;
	root->strlen = len;
	return (root);
}
