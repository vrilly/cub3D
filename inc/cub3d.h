/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 16:55:04 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/04 08:15:12 by tjans         ########   odam.nl         */
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

typedef struct	s_state
{
	int	walking;
	int	rotating;
	int	strafing;
}				t_state;

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

	char			*error;
}				t_game;

void			*reterr(t_game *state, char *err);

int				read_map_from_file(char *path, t_game *state);
int				verify_map(t_map *map);
void			init_background(t_game *state);
int				create_renderer_window(t_game *state);
int				destroy_renderer_window(t_game *state);
int				render_frame(t_game *state);
void			movement_loop(t_game *state);

void			precalc(t_game *state, int x);
void			calc_step(t_game *state);
void			calc_dda(t_game *state);
void			prerendercalc(t_game *state);
void			wallx_calc(t_game *state);

void			start_frame(t_game *state);
void			end_frame(t_game *state);

void			init_sprite_engine(t_game *state, t_map *map);
void			sort_sprites(t_sprite_engine *eng);
void			render_sprites(t_game *state);
void			add_sprite(t_game *state, double x, double y);
void			cast_sprites(t_game *state);

void			rotate_left(t_game *state);
void			rotate_right(t_game *state);
void			shit_rotate(t_game *state);
void			forwards(t_game *state);
void			backwards(t_game *state);
void			left(t_game	*state);
void			right(t_game *state);

int				hook_keyup(int kc, t_game *state);
int				hook_keydown(int kc, t_game *state);

#endif
