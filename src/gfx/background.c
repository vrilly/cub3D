/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   background.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 14:15:05 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/20 14:53:07 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cast_line(t_frame *bg, unsigned int color, int y)
{
	int		x;
	char	*data_addr;

	x = 0;
	data_addr = bg->image_data + (y * bg->size_line);
	while (x < (bg->size_line / 4))
	{
		*(unsigned int*)data_addr = color;
		data_addr += 4;
		x++;
	}
}

void		init_background(t_game *state)
{
	int	y;

	y = 0;
	state->background.image_ptr = mlx_new_image(state->mlx_ptr,
			state->current_map->x_res, state->current_map->y_res);
	state->background.image_data = mlx_get_data_addr(
			state->background.image_ptr, &state->background.bpp,
			&state->background.size_line, &state->background.endian);
	while (y < state->current_map->y_res)
	{
		if (y < state->current_map->y_res / 2)
			cast_line(&state->background, state->current_map->color_ceiling, y);
		else
			cast_line(&state->background, state->current_map->color_floor, y);
		y++;
	}
}
