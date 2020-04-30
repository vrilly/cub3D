/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 19:42:49 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/16 23:32:22 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_game *state)
{
	double	olddirx;
	double	oldplanex;

	olddirx = state->vec.dir_x;
	oldplanex = state->vec.plane_x;
	state->vec.dir_x = olddirx * cos(state->config.cam_speed) -
		state->vec.dir_y * sin(state->config.cam_speed);
	state->vec.dir_y = olddirx * sin(state->config.cam_speed) +
		state->vec.dir_y * cos(state->config.cam_speed);
	state->vec.plane_x = oldplanex * cos(state->config.cam_speed) -
		state->vec.plane_y * sin(state->config.cam_speed);
	state->vec.plane_y = oldplanex * sin(state->config.cam_speed) +
		state->vec.plane_y * cos(state->config.cam_speed);
}

void	rotate_right(t_game *state)
{
	double	olddirx;
	double	oldplanex;

	olddirx = state->vec.dir_x;
	oldplanex = state->vec.plane_x;
	state->vec.dir_x = olddirx * cos(-state->config.cam_speed) -
		state->vec.dir_y * sin(-state->config.cam_speed);
	state->vec.dir_y = olddirx * sin(-state->config.cam_speed) +
		state->vec.dir_y * cos(-state->config.cam_speed);
	state->vec.plane_x = oldplanex * cos(-state->config.cam_speed) -
		state->vec.plane_y * sin(-state->config.cam_speed);
	state->vec.plane_y = oldplanex * sin(-state->config.cam_speed) +
		state->vec.plane_y * cos(-state->config.cam_speed);
}
