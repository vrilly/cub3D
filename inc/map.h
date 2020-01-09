/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 17:21:08 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/09 17:36:05 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

enum			e_map_tile_type {
	TILE_EMPTY = 0,
	TILE_WALL = 1,
	TILE_ITEM = 2,
	TILE_PLAYER = 3
};

typedef struct	s_map
{
	char					map_name[32];

	void					*texture_north;
	void					*texture_south;
	void					*texture_west;
	void					*texture_east;
	void					*texture_sprite;

	enum e_map_tile_type	*mapdata;

	int						color_floor;
	int						color_ceiling;
}				t_map;

t_map			*read_map_from_file(char *path);

#endif
