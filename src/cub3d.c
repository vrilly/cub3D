/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 16:37:53 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/20 13:49:38 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include "cub3d.h"

int	kp_hook(int kc, t_game *state)
{
	if (kc == 123)
		rotate_left(state);
	if (kc == 124)
		rotate_right(state);
	if (kc == 2)
		state->debug = 1;
	if (kc == 126)
		forwards(state);
	if (kc == 125)
		backwards(state);
}

int main(void)
{
	t_game	state;

	ft_bzero(&state, sizeof(t_game));
	state.mlx_ptr = mlx_init();
	if (!state.mlx_ptr)
		return (0);
	state.current_map = read_map_from_file("map.cub", &state);
	if (!state.current_map)
		return -1;
	create_renderer_window(&state);
	state.vec.dir_x = -1;
	state.vec.dir_y = 0;
	state.vec.plane_x = 0;
	state.vec.plane_y = 0.66;
	while (1)
	{
		mlx_loop_hook(state.mlx_ptr, &render_frame, &state);
		mlx_hook(state.window, KeyPress, KeyPressMask, &kp_hook, &state);
		mlx_loop(state.mlx_ptr);
	}
	destroy_renderer_window(&state);
	free(state.current_map);
	return 0;
}
