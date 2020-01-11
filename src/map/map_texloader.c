/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_texloader.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 16:38:31 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/10 17:54:15 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "map.h"
#include "map_seq.h"

static void	*read_file_content(char *path)
{
}

int	load_texture(const char *tex_ident, char *line, void **dst)
{
	void	*texture;

	if (ft_strncmp(line, tex_ident, 2))
		return (0);
	line = ft_strchr(line, ' ');
	if (!*line || !*(line + 1))
		return (0);
	line++;
}
