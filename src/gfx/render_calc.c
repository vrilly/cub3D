/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_calc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 20:17:28 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/04 11:51:25 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_params(t_game *state, int x)
{
	state->rcp.camera_x = 2 * x / (double)state->current_map->x_res - 1;
	state->rcp.rc_dir_x = state->vec.dir_x +
		state->vec.plane_x * state->rcp.camera_x;
	state->rcp.rc_dir_y = state->vec.dir_y +
		state->vec.plane_y * state->rcp.camera_x;
	state->vec.map_x = (int)state->vec.pos_x;
	state->vec.map_y = (int)state->vec.pos_y;
	state->rcp.d_dist_x = fabs(1 / state->rcp.rc_dir_x);
	state->rcp.d_dist_y = fabs(1 / state->rcp.rc_dir_y);
}

void	calc_raycaster_step(t_game *state)
{
	if (state->rcp.rc_dir_x < 0)
	{
		state->rcp.step_x = -1;
		state->rcp.s_dist_x =
			(state->vec.pos_x - state->vec.map_x) * state->rcp.d_dist_x;
	}
	else
	{
		state->rcp.step_x = 1;
		state->rcp.s_dist_x =
			(state->vec.map_x + 1 - state->vec.pos_x) * state->rcp.d_dist_x;
	}
	if (state->rcp.rc_dir_y < 0)
	{
		state->rcp.step_y = -1;
		state->rcp.s_dist_y =
			(state->vec.pos_y - state->vec.map_y) * state->rcp.d_dist_y;
	}
	else
	{
		state->rcp.step_y = 1;
		state->rcp.s_dist_y =
			(state->vec.map_y + 1 - state->vec.pos_y) * state->rcp.d_dist_y;
	}
}

void	calc_dda(t_game *state)
{
	int	mapdata_l_offset;

	state->rcp.hit = 0;
	while (state->rcp.hit == 0)
	{
		if (state->rcp.s_dist_x < state->rcp.s_dist_y)
		{
			state->rcp.s_dist_x += state->rcp.d_dist_x;
			state->vec.map_x += state->rcp.step_x;
			state->rcp.side = 0;
		}
		else
		{
			state->rcp.s_dist_y += state->rcp.d_dist_y;
			state->vec.map_y += state->rcp.step_y;
			state->rcp.side = 1;
		}
		mapdata_l_offset = state->vec.map_y * state->current_map->map_width;
		if (state->current_map->mapdata
				[mapdata_l_offset + state->vec.map_x] == 1)
			state->rcp.hit = 1;
	}
}

void	calc_vert_line(t_game *state)
{
	if (state->rcp.side == 0)
		state->rcp.walldist =
			(state->vec.map_x - state->vec.pos_x +
			(1 - state->rcp.step_x) / 2) / state->rcp.rc_dir_x;
	else
		state->rcp.walldist =
			(state->vec.map_y - state->vec.pos_y +
			(1 - state->rcp.step_y) / 2) / state->rcp.rc_dir_y;
	state->vis.line_height =
		(int)(state->current_map->y_res / state->rcp.walldist);
	state->vis.line_start = -state->vis.line_height / 2 +
		state->current_map->y_res / 2;
	if (state->vis.line_start < 0)
		state->vis.line_start = 0;
	state->vis.line_end = state->vis.line_height / 2 +
		state->current_map->y_res / 2;
	if (state->vis.line_end >= state->current_map->y_res)
		state->vis.line_end = state->current_map->y_res - 1;
}

void	calc_wallx(t_game *state)
{
	if (state->rcp.side == 0)
	{
		state->vis.wall_x = state->vec.pos_y + state->rcp.walldist
			* state->rcp.rc_dir_y;
		if (state->rcp.rc_dir_x > 0)
			state->vis.texture = &state->current_map->texture_east;
		else
			state->vis.texture = &state->current_map->texture_west;
	}
	else
	{
		state->vis.wall_x = state->vec.pos_x + state->rcp.walldist
			* state->rcp.rc_dir_x;
		if (state->rcp.rc_dir_y > 0)
			state->vis.texture = &state->current_map->texture_north;
		else
			state->vis.texture = &state->current_map->texture_south;
	}
	state->vis.wall_x -= floor(state->vis.wall_x);
}
