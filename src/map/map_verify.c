/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_verify.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 08:10:09 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/17 01:49:12 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	map_leaktest(t_map *map, enum e_map_tile_type *mapdata,
		int pos_x, int pos_y)
{
	size_t	offset;

	offset = (pos_y * map->map_width) + pos_x;
	if (mapdata[offset] == TILE_WALL)
		return (1);
	if (pos_x <= 0 || pos_y <= 0 ||
			pos_x >= (int)map->map_width - 1 ||
			pos_y >= (int)map->map_height - 1)
		return (0);
	if (mapdata[offset] == 3)
		return (1);
	mapdata[offset] = 3;
	if (!map_leaktest(map, mapdata, pos_x + 1, pos_y) ||
		!map_leaktest(map, mapdata, pos_x - 1, pos_y) ||
		!map_leaktest(map, mapdata, pos_x, pos_y + 1) ||
		!map_leaktest(map, mapdata, pos_x, pos_y - 1))
		return (0);
	return (1);
}

int			verify_map(t_map *map, t_game *state)
{
	enum e_map_tile_type	*mapdata;

	mapdata = malloc(map->map_height * map->map_width * 4);
	ft_memcpy(mapdata, map->mapdata, map->map_height * map->map_width * 4);
	if (map->x_res > 3200)
		map->x_res = 3200;
	if (map->y_res > 1800)
		map->y_res = 1800;
	if (!map_leaktest(map, mapdata,
				(int)state->vec.pos_x, (int)state->vec.pos_y))
	{
		free(mapdata);
		return ((int)reterr(state, "Map is not enclosed."));
	}
	free(mapdata);
	return (1);
}
