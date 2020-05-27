/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_bonus.c                                           :+:    :+:      */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 12:00:00 by tjans         #+#    #+#                 */
/*   Updated: 2020/05/05 12:00:00 by tjans                                    */
/* ************************************************************************** */

#include "minimap_bonus.h"

static void	draw_tile(t_texture *fb, int x, int y, unsigned int color)
{
	void	*data_ptr;
	int		i;
	int		ii;

	data_ptr = fb->data_ptr + (y * fb->size_line * 10) + (x * 4 * 10);
	i = 0;
	while (i < 10)
	{
		ii = 0;
		while (ii < 10)
		{
			*(unsigned int*)data_ptr = color;
			data_ptr += 4;
			ii++;
		}
		data_ptr += fb->size_line - (10 * 4);
		i++;
	}
}

unsigned int	get_tile_color(t_map *map, int x, int y)
{
	int	map_tile;

	if (x < 0 || y < 0 || x > (int)map->map_width || y > (int)map->map_height)
		return 0xFF666666;
	map_tile = map->mapdata[y * map->map_width + x];
	if (map_tile == TILE_EMPTY)
		return 0x00000000;
	if (map_tile == TILE_WALL)
		return 0xFFFFFFFF;
	if (map_tile == TILE_ITEM)
		return 0xFFFF0000;
	return 0x00000000;
}

void		update(t_game *state, t_texture *fb)
{
	int	px;
	int	py;
	int	ix;
	int iy;

	px = (int)state->vec.pos_x - 4;
	py = (int)state->vec.pos_y - 4;
	iy = 0;
	while (iy < 9)
	{
		ix = 0;
		while (ix < 9)
		{
			draw_tile(fb, ix, iy,
					get_tile_color(state->current_map, px + ix, py + iy));
			ix++;
		}
		iy++;
	}
}
