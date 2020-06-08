/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_verify.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 08:10:09 by tjans         #+#    #+#                 */
/*   Updated: 2020/03/02 19:19:21 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	map_leaktest(t_map *map, enum e_map_tile_type *mapdata,
		int pos_x, int pos_y)
{
	int	offset;

	offset = pos_y * map->map_width + pos_x;
	if (mapdata[offset] == TILE_WALL)
		return (1);
	if (pos_x <= 0 || pos_y <= 0 ||
			pos_x >= map->map_width - 1 ||
			pos_y >= map->map_height - 1)
	{
		ft_fprintf(2, "Map not enclosed x:%d y:%d\n", pos_x, pos_y);
		return (0);
	}
	if (mapdata[offset] == TILE_LEAKTEST)
		return (1);
	mapdata[offset] = TILE_LEAKTEST;
	if (!map_leaktest(map, mapdata, pos_x + 1, pos_y) ||
		!map_leaktest(map, mapdata, pos_x - 1, pos_y) ||
		!map_leaktest(map, mapdata, pos_x, pos_y + 1) ||
		!map_leaktest(map, mapdata, pos_x, pos_y - 1) ||
		!map_leaktest(map, mapdata, pos_x + 1, pos_y + 1) ||
		!map_leaktest(map, mapdata, pos_x - 1, pos_y - 1) ||
		!map_leaktest(map, mapdata, pos_x + 1, pos_y - 1) ||
		!map_leaktest(map, mapdata, pos_x - 1, pos_y + 1))
		return (0);
	return (1);
}

static void	check_resolution(t_game *state)
{
	int	max_x;
	int	max_y;
	int	changed;

	changed = 0;
	if (state->current_map->x_res > 16384 || state->current_map->y_res > 16384)
		changed = 1;
	if (state->current_map->x_res > 16384)
		state->current_map->x_res = 16384;
	if (state->current_map->y_res > 16384)
		state->current_map->y_res = 16384;
	if (state->screenshot == OFFSCREEN_SCREENSHOT)
		return ;
	mlx_get_screen_size(state->mlx_ptr, &max_x, &max_y);
	if (state->current_map->x_res > max_x ||
	state->current_map->y_res > max_y)
		changed = 1;
	if (state->current_map->x_res > max_x)
		state->current_map->x_res = max_x;
	if (state->current_map->y_res > max_y)
		state->current_map->y_res = max_y;
	if (changed)
		ftlog(LOG_WARN, "Resolution corrected to max value");
}

static int	check_mandatory_elems(t_map *map)
{
	if (!map->texture_east.img_ptr ||
	!map->texture_north.img_ptr ||
	!map->texture_south.img_ptr ||
	!map->texture_west.img_ptr ||
	!map->texture_sprite.img_ptr)
		return (0);
	if (map->color_ceiling == 0xFFFFFFFF || map->color_floor == 0xFFFFFFFF)
		return (0);
	return (1);
}

int			verify_map(t_map *map, t_game *state)
{
	enum e_map_tile_type	*mapdata;
	int						ret;

	ret = 1;
	mapdata = malloc((size_t)map->map_height * map->map_width * 4);
	if (!mapdata)
		safe_exit(state, -1, "malloc fail");
	ft_memcpy(mapdata, map->mapdata,
			(size_t)map->map_height * map->map_width * 4);
	check_resolution(state);
	if (!(int)state->vec.pos_x || !(int)state->vec.pos_y)
		return ((int)set_error(state, "Missing spawn location"));
	if (!map_leaktest(map, mapdata,
				(int)state->vec.pos_x, (int)state->vec.pos_y))
		ret = (int)set_error(state, "Map is not enclosed.");
	if (!check_mandatory_elems(map))
		ret = (int)set_error(state, "Mandantory map elements are missing");
	free(mapdata);
	return (ret);
}
