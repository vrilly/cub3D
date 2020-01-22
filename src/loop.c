/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:29:29 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/22 17:39:58 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	movement_loop(t_game *state)
{
	if (state->state.walking == 1)
		forwards(state);
	if (state->state.walking == 2)
		backwards(state);
	if (state->state.rotating == 1)
		rotate_left(state);
	if (state->state.rotating == 2)
		rotate_right(state);
}

void	dbg_loop(t_game *state)
{
	char	dbg_line[512];

	sprintf(dbg_line, "dirx: %.4f diry: %.4f",
			state->vec.dir_x, state->vec.dir_y);
	mlx_string_put(state->mlx_ptr, state->window, 0, 16,
			0x00FFFFFF, dbg_line);
	sprintf(dbg_line, "planex: %.4f planey: %.4f",
			state->vec.plane_x, state->vec.plane_y);
	mlx_string_put(state->mlx_ptr, state->window, 0, 32,
			0x00FFFFFF, dbg_line);
}
