/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 19:42:49 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/20 13:51:15 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	forwards(t_game *state)
{
	state->vec.pos_x += state->vec.dir_x * 0.5;
	state->vec.pos_y += state->vec.dir_y * 0.5;
}

void	backwards(t_game *state)
{
	state->vec.pos_x -= state->vec.dir_x * 0.5;
	state->vec.pos_y -= state->vec.dir_y * 0.5;
}

void	rotate_left(t_game *state)
{
	double	olddirx;
	double	oldplanex;

	olddirx = state->vec.dir_x;
	oldplanex = state->vec.plane_x;
	state->vec.dir_x = olddirx * cos(0.0835) -
		state->vec.dir_y * sin(0.0835);
	state->vec.dir_y = olddirx * sin(0.0835) +
		state->vec.dir_y * cos(0.0835);
	state->vec.plane_x = oldplanex * cos(0.0835) -
		state->vec.plane_y * sin(0.0835);
	state->vec.plane_y = oldplanex * sin(0.0835) +
		state->vec.plane_y * cos(0.0835);
}

void	rotate_right(t_game *state)
{
	double	olddirx;
	double	oldplanex;

	olddirx = state->vec.dir_x;
	oldplanex = state->vec.plane_x;
	state->vec.dir_x = olddirx * cos(-0.0835) -
		state->vec.dir_y * sin(-0.0835);
	state->vec.dir_y = olddirx * sin(-0.0835) +
		state->vec.dir_y * cos(-0.0835);
	state->vec.plane_x = oldplanex * cos(-0.0835) -
		state->vec.plane_y * sin(-0.0835);
	state->vec.plane_y = oldplanex * sin(-0.0835) +
		state->vec.plane_y * cos(-0.0835);
}
