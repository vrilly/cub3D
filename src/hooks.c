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

#include "cub3d.h"

int		hook_keydown(int kc, t_game *state)
{
	if (kc == state->config.k_a)
		state->state.strafing = LEFT;
	if (kc == state->config.k_d)
		state->state.strafing = RIGHT;
	if (kc == state->config.k_w)
		state->state.walking = FORWARDS;
	if (kc == state->config.k_s)
		state->state.walking = BACKWARDS;
	if (kc == state->config.k_left)
		state->state.rotating = LEFT;
	if (kc == state->config.k_right)
		state->state.rotating = RIGHT;
	return (1);
}

int		hook_keyup(int kc, t_game *state)
{
	if (kc == state->config.k_a || kc == state->config.k_d)
		state->state.strafing = NOT_MOVING;
	if (kc == state->config.k_w || kc == state->config.k_s)
		state->state.walking = NOT_MOVING;
	if (kc == state->config.k_left || kc == state->config.k_right)
		state->state.rotating = NOT_MOVING;
	if (kc == state->config.k_esc)
		safe_exit(state, 0, NULL);
	if (kc == state->config.k_prtscr)
		state->screenshot = SCREENSHOT;
	return (1);
}

/*
** I hardcoded X11 defines to save the evaluator the effort of having to
** install XQuartz through msc before evaluating.
*/

void	init_window_hooks(void *window, t_game *state)
{
	mlx_hook(window, 2, (1L << 0), &hook_keydown, state);
	mlx_hook(window, 3, (1L << 1), &hook_keyup, state);
	mlx_hook(state->window, 17, 0, (int (*)()) &exit, 0);
}
