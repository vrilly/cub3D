/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 16:55:04 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/13 16:00:36 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <libft.h>
# include "texture.h"

enum			e_map_tile_type {
	TILE_EMPTY = 0,
	TILE_WALL = 1,
	TILE_ITEM = 2
};

typedef struct	s_map
{
	char					map_name[32];

	t_texture				texture_north;
	t_texture				texture_south;
	t_texture				texture_west;
	t_texture				texture_east;
	t_texture				texture_sprite;

	enum e_map_tile_type	*mapdata;
	unsigned int			map_width;
	unsigned int			map_height;


	unsigned int			color_floor;
	unsigned int			color_ceiling;

	int						x_res;
	int						y_res;
}				t_map;

typedef struct	s_game
{
	t_map	*current_map;

	void	*mlx_ptr;

	float	camera_x;
	float	camera_y;
}				t_game;

t_map			*read_map_from_file(char *path, t_game *state);

#endif
