/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:20:03 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/23 18:14:22 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	hook_keydown(int kc, t_game *state)
{
	if (kc == state->config.k_a)
		state->state.strafing = 1;
	if (kc == state->config.k_d)
		state->state.strafing = 2;
	if (kc == state->config.k_w)
		state->state.walking = 1;
	if (kc == state->config.k_s)
		state->state.walking = 2;
	if (kc == state->config.k_left)
		state->state.rotating = 1;
	if (kc == state->config.k_right)
		state->state.rotating = 2;
	return (1);
}

int	hook_keyup(int kc, t_game *state)
{
	if (kc == state->config.k_a || kc == state->config.k_d)
		state->state.strafing = 0;
	if (kc == state->config.k_w || kc == state->config.k_s)
		state->state.walking = 0;
	if (kc == state->config.k_left || kc == state->config.k_right)
		state->state.rotating = 0;
	if (kc == state->config.k_esc)
		exit(0);
	return (1);
}
