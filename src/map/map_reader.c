/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_reader.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 17:33:47 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/11 17:07:52 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map_seq.h"

static int	(*g_read_seq[2])(t_fdstream *, t_map *) =
{
	map_reader_seq_resolution,
	map_reader_seq_textures
};

t_map		*read_map_from_file(char *path, t_game *state)
{
	t_map		*map;
	t_fdstream	*fs;
	int			i;

	i = 0;
	fs = fd_open(path, O_RDONLY);
	if (!fs)
		return (NULL);
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	while (i < 2)
	{
		if (!g_read_seq[i](fs, map))
		{
			free(map);
			return (NULL);
		}
		i++;
	}
	fd_close(fs);
	free(fs);
	ft_strlcpy(map->map_name, path, 32);
	return (map);
}
