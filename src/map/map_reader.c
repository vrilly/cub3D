/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_reader.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 17:33:47 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/04 08:15:40 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map_seq.h"

static int	(*g_read_seq[4])(t_fdstream *, t_map *, t_game *) =
{
	&map_reader_seq_resolution,
	&map_reader_seq_textures,
	&map_reader_seq_colors,
	&map_reader_seq_mapdata
};

int			read_map_from_file(char *path, t_game *state)
{
	t_map		*map;
	t_fdstream	*fs;
	int			i;

	i = 0;
	fs = fd_open(path, O_RDONLY);
	if (!fs)
		return ((int)reterr(state, strerror(errno)));
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return ((int)reterr(state, strerror(errno)));
	state->current_map = map;
	while (i < 4)
	{
		if (!g_read_seq[i](fs, map, state))
		{
			free(map);
			return ((int)reterr(state, "malformed map"));
		}
		i++;
	}
	fd_close(fs);
	free(fs);
	ft_strlcpy(map->map_name, path, 32);
	return (verify_map(map));
}
