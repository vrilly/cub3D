/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 18:08:12 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/13 20:14:12 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	precalc(t_game *state, int x)
{
	state->rcp.camera_x = 2 * x / state->current_map->x_res - 1;
	state->rcp.rc_dir_x = state->vec.dir_x +
		state->vec.plane_x * state->rcp.camera_x;
	state->rcp.rc_dir_y = state->vec.dir_y +
		state->vec.plane_y * state->rcp.camera_x;
	state->vec.map_x = (int)state->vec.pos_x;
	state->vec.map_y = (int)state->vec.pos_y;
	state->rcp.d_dist_x = fabs(1 / state->rcp.rc_dir_x);
	state->rcp.d_dist_y = fabs(1 / state->rcp.rc_dir_y);
}

static void	calc_step(t_game *state)
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

int			render_frame(t_game *state)
{
	int	x;

	x = 0;
	while (x < state->current_map->x_res)
	{
		precalc(state, x);
		calc_step(state);
		x++;
	}
	mlx_do_sync(state->mlx_ptr);
	return (1);
}
