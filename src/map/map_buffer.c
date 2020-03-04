/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_buffer.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 20:18:43 by tjans         #+#    #+#                 */
/*   Updated: 2020/03/02 19:49:24 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void				copy_line(t_mapbuffer *node,
		enum e_map_tile_type *mapdata)
{
	int		i;
	char	c;

	i = 0;
	while (i < node->str_size)
	{
		c = node->line[i];
		if (c == ' ')
			c = '0';
		*mapdata = c -
				((c == 'N' || c == 'S' || c == 'E' || c == 'W') ? 0 : '0');
		mapdata++;
		i++;
	}
}

t_mapbuffer				*mbuf_create(char *line, int line_size)
{
	t_mapbuffer	*buff;

	buff = ft_calloc(1, sizeof(t_mapbuffer));
	if (!buff)
		return (NULL);
	buff->line = line;
	buff->line_size = line_size;
	buff->str_size = ft_strlen(line);
	buff->lines = 1;
	return (buff);
}

void					mbuf_append(t_mapbuffer *root, t_mapbuffer *new)
{
	root->lines++;
	if (new->line_size > root->line_size_max)
		root->line_size_max = new->line_size;
	while (root->next)
		root = root->next;
	root->next = new;
}

enum e_map_tile_type	*mbuf_finalize(t_mapbuffer *root, int *map_height)
{
	int						line_size;
	int						lines;
	int						i;
	enum e_map_tile_type	*mapdata;

	line_size = root->line_size_max;
	lines = root->lines;
	mapdata = ft_calloc(lines, line_size * sizeof(enum e_map_tile_type));
	if (!mapdata)
		return (NULL);
	i = 0;
	while (i < lines)
	{
		copy_line(root, mapdata + (line_size * i));
		i++;
		root = root->next;
	}
	*map_height = lines;
	return (mapdata);
}

void					mbuf_destroy(t_mapbuffer *root)
{
	t_mapbuffer	*prevnode;

	prevnode = root;
	while (prevnode->next)
	{
		root = prevnode->next;
		free(prevnode->line);
		free(prevnode);
		prevnode = root;
	}
	free(prevnode->line);
	free(prevnode);
}
