/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parser.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 13:37:55 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/13 20:13:14 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map_seq.h"

static int	calc_map_width(char *line)
{
	int	map_width;

	map_width = 0;
	while (*line)
	{
		if (*line >= '0' && *line <= '2')
			map_width++;
		line++;
	}
	return (map_width);
}

static int	is_pdir(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	set_spawn(char direction, unsigned int cl, int x, t_game *map)
{
	(void)direction;
	map->vec.pos_x = x;
	map->vec.pos_y = cl;
}

static int	parse_line(char *line, enum e_map_tile_type *mapdata,
		unsigned int cl, t_game *state)
{
	int	line_c;
	int	i;

	i = 0;
	while (line[i])
	{
		while (line[i] == ' ' && line[i + 1] != '\0')
			i++;
		line_c = line[i] - '0';
		if (line_c < 0 || line_c > 2 || is_pdir(line_c))
			return (0);
		if (is_pdir(line_c))
			set_spawn(line_c, cl, i, state);
		else
			*mapdata = line_c;
		mapdata++;
		i++;
	}
	return (1);
}

int			map_reader_seq_mapdata(t_fdstream *fs, t_map *map, t_game *state)
{
	unsigned int	curr_line;
	char			*line;
	int				ret;

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
		if (!parse_line(line, map->mapdata + (curr_line * map->map_width),
					curr_line, state))
			return (0);
		free(line);
		ret = fd_readline(fs, &line);
		curr_line++;
	}
	free(line);
	map->map_height = curr_line;
	return (1);
}
