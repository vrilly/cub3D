/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 16:55:04 by tjans         #+#    #+#                 */
/*   Updated: 2020/03/01 20:11:02 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <string.h>
# include <sys/errno.h>
# include <fcntl.h>
# include <mlx.h>
# include <libft.h>
# include <printf.h>
# include <math.h>
# include "texture.h"
# include "gfx.h"
# include "config.h"
# include "ftlog.h"
# include "cub3d_error.h"
# include "plugin_bonus.h"

enum			e_map_tile_type {
	TILE_EMPTY = 0,
	TILE_WALL = 1,
	TILE_ITEM = 2,
	TILE_LEAKTEST = 3
};

typedef enum	e_direction {
	NOT_MOVING = 0,

	FORWARDS = 1,
	BACKWARDS = 2,

	LEFT = 1,
	RIGHT = 2
}				t_direction;

typedef enum	e_ss_mode {
	NO_SCREENSHOT,
	SCREENSHOT,
	OFFSCREEN_SCREENSHOT
}				t_ss_mode;

/*
** Current map loaded into the game engine
** Everything configured in the map file will be loaded into this struct
** And stuff like textures will be loaded too by the appropriate file loader
** for that filetype
*/

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

/*
** Vectors for saving the player position, and viewport direction + FOV
*/

typedef struct	s_vectors
{
	double	pos_x;
	double	pos_y;

	double	dir_x;
	double	dir_y;

	double	plane_x;
	double	plane_y;

	int		map_x;
	int		map_y;
}				t_vectors;

/*
** Input state.
** Allows for multiple actions at the same time by listening to keydown and
** keyup events. The enums have three states for every manipulation plane
*/

typedef struct	s_state
{
	t_direction	walking;
	t_direction	rotating;
	t_direction	strafing;
}				t_state;

/*
** Main game struct. The complete state of the game engine is saved in here
** Theoretically you could dump this to a file, reload it and continue exactly
** Where you left off, but that is not a valid bonus worth points.
*/

typedef struct	s_game
{
	t_map			*current_map;
	t_config		config;
	t_state			state;

	void			*mlx_ptr;
	void			*window;
	t_frame			frame;
	t_frame			background;

	t_vectors		vec;
	t_rc_params		rcp;
	t_draw_p		vis;
	t_sprite_engine	spr;

	t_pluginlist	*plugins;

	char			*error;
	char			*map_path;
	t_ss_mode		screenshot;
}				t_game;

/*
** Peacefully destroys the renderer window and closes the program
** If error is set then it'll also log it before exiting
*/

void			safe_exit(t_game *state, int ret, char *error);

int				read_map_from_file(char *path, t_game *state);
void			init_background(t_game *state);
int				create_renderer_window(t_game *state);
int				destroy_renderer_window(t_game *state);
void			init_window_hooks(void *window, t_game *state);
int				render_frame(t_game *state);
void			movement_loop(t_game *state);

void			rotate_left(t_game *state);
void			rotate_right(t_game *state);
void			forwards(t_game *state);
void			backwards(t_game *state);
void			left(t_game	*state);
void			right(t_game *state);

int				hook_keyup(int kc, t_game *state);
int				hook_keydown(int kc, t_game *state);

#endif
