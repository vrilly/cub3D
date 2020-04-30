/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:20:03 by tjans         #+#    #+#                 */
/*   Updated: 2020/03/04 19:20:02 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
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
		safe_exit(state, 0, NULL);
	if (kc == state->config.k_prtscr)
		state->screenshot = 1;
	return (1);
}

int	init_window_hooks(void *window, t_game *state)
{
	mlx_hook(window, KeyPress, KeyPressMask, &hook_keydown, state);
	mlx_hook(window, KeyRelease, KeyReleaseMask, &hook_keyup, state);
	mlx_hook(state->window, DestroyNotify, 0, (int (*)()) &exit, 0);
}
