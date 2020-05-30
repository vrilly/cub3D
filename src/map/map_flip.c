/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_flip.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 01:09:20 by tjans         #+#    #+#                 */
/*   Updated: 2020/03/01 17:45:56 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	is_pdir(int c)
{
	return ((c == 'N' || c == 'S' || c == 'E' || c == 'W'));
}

static void	set_spawn(int direction, unsigned int cl, int x, t_game *map)
{
	map->vec.pos_x = x + 0.5;
	map->vec.pos_y = cl + 0.5;
	if (direction == 'N' || direction == 'S')
	{
		map->vec.dir_x = 0;
		map->vec.dir_y = (direction == 'N') ? -1 : 1;
		map->vec.plane_x = (direction == 'N') ? -0.66 : 0.66;
		map->vec.plane_y = 0;
	}
	if (direction == 'E' || direction == 'W')
	{
		map->vec.dir_x = (direction == 'W') ? -1 : 1;
		map->vec.dir_y = 0;
		map->vec.plane_x = 0;
		map->vec.plane_y = (direction == 'W') ? 0.66 : -0.66;
	}
}

static void	write_line(int x, int *dst, t_map *map, t_game *state)
{
	unsigned int	i;
	int				*src;
	static int		spawnset = 0;

	i = 0;
	src = (int*)map->mapdata + map->map_width - 1 - x;
	while (i < map->map_height)
	{
		*(dst + (map->map_width * i)) = *(src + (map->map_width * i));
		if (is_pdir(*(dst + (map->map_width * i))) && !spawnset)
		{
			set_spawn(*(dst + (map->map_width * i)), i, x, state);
			spawnset++;
		}
		else if (is_pdir(*(dst + (map->map_width * i))) && spawnset)
			safe_exit(state, -1, "Multiple spawn locations!");
		else if (*(dst + (map->map_width * i)) == 2)
			add_sprite(state, x, i);
		else
			execute_spawn_hook(state, (char)*(dst + (map->map_width * i)),
					x, (int)i);
		i++;
	}
}

int			map_flip(t_map *map, t_game *state)
{
	unsigned int			x;
	enum e_map_tile_type	*new;

	x = 0;
	new = malloc(sizeof(enum e_map_tile_type)
			* map->map_width * map->map_height);
	if (!new)
		safe_exit(state, -1, "malloc fail");
	while (x < map->map_width)
	{
		write_line(x, (int*)new + x, map, state);
		x++;
	}
	free(map->mapdata);
	map->mapdata = new;
	return (1);
}
