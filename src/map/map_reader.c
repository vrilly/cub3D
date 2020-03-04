/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_reader.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 17:33:47 by tjans         #+#    #+#                 */
/*   Updated: 2020/03/04 18:55:50 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	maplen(char *line)
{
	int	i;

	i = 0;
	while (*line)
	{
		if (ft_isdigit(*line) || *line == ' ')
			i++;
		if (*line == 'N' || *line == 'E' || *line == 'S' || *line == 'W')
			i++;
		line++;
	}
	return (i);
}

static int	read_mapdata(t_fdstream *fs, char *first_line, t_game *state)
{
	char		*line;
	int			ret;
	t_mapbuffer	*buff;

	init_sprite_engine(state, state->current_map);
	buff = mbuf_create(first_line, maplen(first_line));
	ret = fd_readline(fs, &line);
	while (ret == 1)
	{
		mbuf_append(buff, mbuf_create(line, maplen(line)));
		ret = fd_readline(fs, &line);
		if (!*line)
		{
			ret = 0;
			free(line);
		}
	}
	state->current_map->mapdata = mbuf_finalize(buff,
			(int*)&state->current_map->map_height);
	if (!state->current_map->mapdata)
		safe_exit(state, -1, "malloc fail");
	state->current_map->map_width = buff->line_size_max;
	mbuf_destroy(buff);
	return (map_flip(state->current_map, state));
}

static int	process_line(char *line, t_game *state)
{
	char		*prefix;
	char		*arg;
	t_mplookup	*handler;

	prefix = line;
	if (ft_isdigit(*prefix) || *prefix == ' ')
		return (2);
	arg = strchr(prefix, ' ');
	if (!arg)
		return ((int)reterr(state, "Unexpected end of line"));
	arg++;
	handler = find_func(prefix);
	if (handler)
	{
		while (*arg == ' ' && *(arg + 1))
			arg++;
		return (handler->func(arg, state));
	}
	else
		ftlog(LOG_INFO, "Unsupported element ignored");
	return (1);
}

static int	linereader(t_fdstream *fs, t_game *state)
{
	char	*line;
	int		ret;
	int		p_ret;

	ret = fd_readline_sb(fs, &line);
	while (ret == 1)
	{
		p_ret = process_line(line, state);
		if (p_ret == 2)
			read_mapdata(fs, line, state);
		else
			free(line);
		if (!p_ret)
			return (0);
		if (p_ret == 2)
			return (1);
		ret = fd_readline_sb(fs, &line);
	}
	return (ret != -1);
}

int			read_map_from_file(char *path, t_game *state)
{
	t_map		*map;
	t_fdstream	*fs;
	int			ret;

	fs = fd_open(path, O_RDONLY);
	if (!fs)
		return ((int)reterr(state, strerror(errno)));
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return ((int)reterr(state, strerror(errno)));
	map->color_floor = 0xFFFFFFFF;
	map->color_ceiling = 0xFFFFFFFF;
	state->current_map = map;
	ret = linereader(fs, state);
	fd_close(fs);
	free(fs);
	ft_strlcpy(map->map_name, path, 32);
	if (!ret)
		return ((int)reterr(state, "unknown error during map parsing"));
	return (verify_map(map, state));
}
