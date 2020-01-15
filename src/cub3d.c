/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 16:37:53 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/15 18:39:21 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"

int	key_hook(int kc, t_game *state)
{
	dump_gamestate(state);
	return (1);
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
	printf("cub3D\ncolor test:\nF: %#x\nC: %#x\n", state.current_map->color_floor, state.current_map->color_ceiling);
	create_renderer_window(&state);
	state.vec.dir_x = -1;
	state.vec.dir_y = 0;
	state.vec.plane_x = 0;
	state.vec.plane_y = 0.66;
	while (1)
	{
		mlx_loop_hook(state.mlx_ptr, &render_frame, &state);
		mlx_key_hook(state.window, &key_hook, &state);
		mlx_loop(state.mlx_ptr);
	}
	destroy_renderer_window(&state);
	free(state.current_map);
	return 0;
}
