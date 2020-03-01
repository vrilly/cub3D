/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 17:28:40 by tjans         #+#    #+#                 */
/*   Updated: 2020/03/01 20:27:06 by tjans         ########   odam.nl         */
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

	if (state->window)
		mlx_put_image_to_window(state->mlx_ptr, state->window,
				state->frame.image_ptr, 0, 0);
	if (state->screenshot)
	{
		bmp = new_bitmap(state->current_map->x_res,
				state->current_map->y_res);
		if (!bmp)
			safe_exit(state, -1, "malloc fail");
		if (!frame_to_bitmap(&state->frame, bmp))
			safe_exit(state, -1, "malloc fail");
		if (!write_bitmap_to_file("screencap.bmp", bmp))
			ftlog(LOG_ERROR, "Screenshot failed");
		if (state->screenshot == 2)
			safe_exit(state, 0, NULL);
		state->screenshot = 0;
	}
	mlx_destroy_image(state->mlx_ptr, state->frame.image_ptr);
}
