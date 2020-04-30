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
	if (state->state.walking == 1)
		forwards(state);
	if (state->state.walking == 2)
		backwards(state);
	if (state->state.rotating == 1)
		rotate_left(state);
	if (state->state.rotating == 2)
		rotate_right(state);
	if (state->state.strafing == 1)
		left(state);
	if (state->state.strafing == 2)
		right(state);
}
