/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:29:29 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/23 18:06:14 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	movement_loop(t_game *state)
{
	if (state->state.walking == FORWARDS)
		forwards(state);
	if (state->state.walking == BACKWARDS)
		backwards(state);
	if (state->state.rotating == LEFT)
		rotate_left(state);
	if (state->state.rotating == RIGHT)
		rotate_right(state);
	if (state->state.strafing == LEFT)
		left(state);
	if (state->state.strafing == RIGHT)
		right(state);
}
