/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 16:08:44 by tjans         #+#    #+#                 */
/*   Updated: 2020/03/01 20:02:17 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_renderer_window(t_game *state)
{
	void	*win_ptr;

	if (state->screenshot == OFFSCREEN_SCREENSHOT)
	{
		state->window = NULL;
		return (1);
	}
	win_ptr = mlx_new_window(
			state->mlx_ptr,
			state->current_map->x_res,
			state->current_map->y_res,
			state->current_map->map_name);
	if (!win_ptr)
		return (0);
	state->window = win_ptr;
	return (1);
}

int	destroy_renderer_window(t_game *state)
{
	if (state->window)
		mlx_destroy_window(state->mlx_ptr, state->window);
	state->window = NULL;
	return (1);
}
