/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 16:37:53 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/20 14:08:21 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include "cub3d.h"

int	kp_hook(int kc, t_game *state)
{
	if (kc == state->config.k_a)
		rotate_left(state);
	if (kc == state->config.k_d)
		rotate_right(state);
	if (kc == state->config.k_w)
		forwards(state);
	if (kc == state->config.k_s)
		backwards(state);
	if (kc == state->config.k_esc)
		exit(0);
	printf("%d\n", kc);
	return (1);
}

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
	return (0);
}
