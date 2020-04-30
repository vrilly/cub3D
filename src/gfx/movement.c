/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 17:24:54 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/17 01:47:23 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	forwards(t_game *state)
{
	double	nx;
	double	ny;

	nx = state->vec.pos_x + state->vec.dir_x * state->config.mov_speed;
	ny = state->vec.pos_y + state->vec.dir_y * state->config.mov_speed;
	if (state->current_map->mapdata[((int)ny *
		state->current_map->map_width) + (int)nx]
			== TILE_WALL)
		return ;
	state->vec.pos_x = nx;
	state->vec.pos_y = ny;
}

void	backwards(t_game *state)
{
	double	nx;
	double	ny;

	nx = state->vec.pos_x - state->vec.dir_x * state->config.mov_speed;
	ny = state->vec.pos_y - state->vec.dir_y * state->config.mov_speed;
	if (state->current_map->mapdata[((int)ny *
		state->current_map->map_width) + (int)nx]
			== TILE_WALL)
		return ;
	state->vec.pos_x = nx;
	state->vec.pos_y = ny;
}

void	left(t_game *state)
{
	double	nx;
	double	ny;

	nx = state->vec.pos_x - state->vec.plane_x * state->config.mov_speed;
	ny = state->vec.pos_y - state->vec.plane_y * state->config.mov_speed;
	if (state->current_map->mapdata[((int)ny *
		state->current_map->map_width) + (int)nx]
			== TILE_WALL)
		return ;
	state->vec.pos_x = nx;
	state->vec.pos_y = ny;
}

void	right(t_game *state)
{
	double	nx;
	double	ny;

	nx = state->vec.pos_x + state->vec.plane_x * state->config.mov_speed;
	ny = state->vec.pos_y + state->vec.plane_y * state->config.mov_speed;
	if (state->current_map->mapdata[((int)ny *
		state->current_map->map_width) + (int)nx]
			== TILE_WALL)
		return ;
	state->vec.pos_x = nx;
	state->vec.pos_y = ny;
}
