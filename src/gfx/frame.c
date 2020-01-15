/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 17:28:40 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/15 18:13:44 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_frame(t_game *state)
{
	state->frame.image_ptr = mlx_new_image(state->mlx_ptr,
			state->current_map->x_res, state->current_map->y_res);
	state->frame.image_data = mlx_get_data_addr(state->frame.image_ptr,
			&state->frame.bpp, &state->frame.size_line, &state->frame.endian); 
}

void	end_frame(t_game *state)
{
	static int frame = 0;
	mlx_put_image_to_window(state->mlx_ptr, state->window,
			state->frame.image_ptr, 0, 0);
	mlx_destroy_image(state->mlx_ptr, state->frame.image_ptr);
	frame++;
	if (frame % 60 == 0)
		printf("F %d\n", frame);
}
