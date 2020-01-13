/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 16:37:53 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/13 17:53:05 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"

int main(void)
{
	t_game	state;

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
		mlx_loop(state.mlx_ptr);
	}
	destroy_renderer_window(&state);
	free(state.current_map);
	return 0;
}
