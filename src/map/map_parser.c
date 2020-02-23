/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parser.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 13:37:55 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/23 18:08:02 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int			map_reader_seq_mapdata(t_fdstream *fs, t_map *map, t_game *state)
{
	char			*line;
	int				ret;
	t_mapbuffer		*buff;

	init_sprite_engine(state, map);
	ret = fd_readline_sb(fs, &line);
	if (ret != 1)
		return (0);
	buff = NULL;
	while (ret == 1)
	{
		if (buff)
			mbuf_append(buff, mbuf_create(line, ft_strlen(line)));
		else
			buff = mbuf_create(line, ft_strlen(line));
		ret = fd_readline_sb(fs, &line);
	}
	map->mapdata = mbuf_finalize(buff, (int*)&map->map_height);
	mbuf_destroy(buff);
	return (1);
}
