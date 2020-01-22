/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 16:37:53 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/22 18:06:13 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include "cub3d.h"

int main(void)
{
	t_game	state;

	ft_bzero(&state, sizeof(t_game));
	default_config(&state.config);
	state.mlx_ptr = mlx_init();
	if (!state.mlx_ptr)
		return (0);
	state.current_map = read_map_from_file("map.cub", &state);
	if (!state.current_map)
		return -1;
	init_background(&state);
	create_renderer_window(&state);
	while (1)
	{
		mlx_loop_hook(state.mlx_ptr, &render_frame, &state);
		mlx_hook(state.window, KeyPress, KeyPressMask, &hook_keydown, &state);
		mlx_hook(state.window, KeyRelease, KeyReleaseMask, &hook_keyup,
				&state);
		mlx_hook(state.window, DestroyNotify, 0, (int (*)())&exit, 0);
		mlx_loop(state.mlx_ptr);
	}
	return (0);
}
