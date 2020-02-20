/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 17:28:40 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/17 20:24:19 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "bitmap.h"

void	start_frame(t_game *state)
{
	state->frame.image_ptr = mlx_new_image(state->mlx_ptr,
			state->current_map->x_res, state->current_map->y_res);
	state->frame.image_data = mlx_get_data_addr(state->frame.image_ptr,
			&state->frame.bpp, &state->frame.size_line, &state->frame.endian);
	ft_memcpy(state->frame.image_data, state->background.image_data,
			state->background.size_line * state->current_map->y_res);
}

void	end_frame(t_game *state)
{
	t_bitmap	*bmp;

	mlx_put_image_to_window(state->mlx_ptr, state->window,
			state->frame.image_ptr, 0, 0);
	if (state->screenshot)
	{
		bmp = new_bitmap(state->current_map->x_res,
				state->current_map->y_res);
		frame_to_bitmap(&state->frame, bmp);
		write_bitmap_to_file("screencap.bmp", bmp);
		state->screenshot = 0;
	}
	mlx_destroy_image(state->mlx_ptr, state->frame.image_ptr);
}
