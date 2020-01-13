/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parser.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 13:37:55 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/13 15:01:41 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map_seq.h"

static int	calc_map_width(char *line)
{
	int	map_width;

	map_width = 0;
	while (*line)
	{
		if (*line >= '0' && *line <= '3')
			map_width++;
		line++;
	}
	return (map_width);
}

static int	parse_line(char *line, enum e_map_tile_type *mapdata)
{
	int	line_c;

	while (*line)
	{
		while (*line == ' ' && *(line + 1) != '\0')
			line++;
		line_c = *line - '0';
		if (line_c < 0 || line_c > 3)
			return (0);
		*mapdata = line_c;
		mapdata++;
		line++;
	}
	return (1);
}

int	map_reader_seq_mapdata(t_fdstream *fs, t_map *map, t_game *state)
{
	unsigned int	curr_line;
	char			*line;
	int				ret;

	(void)state;
	curr_line = 0;
	ret = fd_readline(fs, &line);
	if (ret != 1)
		return (0);
	map->map_width = calc_map_width(line);
	while (ret == 1)
	{
		map->mapdata = ft_realloc_safe(map->mapdata,
			curr_line * map->map_width * sizeof(enum e_map_tile_type),
			(curr_line + 1) * map->map_width * sizeof(enum e_map_tile_type));
		if (!parse_line(line, map->mapdata + (curr_line * map->map_width)))
			return (0);
		ret = fd_readline(fs, &line);
		curr_line++;
	}
	map->map_height = curr_line;
	return (1);
}
