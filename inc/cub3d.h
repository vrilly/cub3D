/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 16:55:04 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/11 17:11:49 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <libft.h>

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

	int						x_res;
	int						y_res;
}				t_map;

typedef struct	s_game
{
	t_map	*current_map;

	void	*mlx_ptr;
}				t_game;

t_map			*read_map_from_file(char *path, t_game *state);

#endif
