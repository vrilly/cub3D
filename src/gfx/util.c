/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 12:00:00 by tjans         #+#    #+#                 */
/*   Updated: 2020/05/05 12:00:00 by tjans                                    */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_tex(t_game *state, t_texture *tex, int x, int y)
{
	int	yp;
	int	offset;
	int t_offset;

	yp = 0;
	if (tex->width + x > state->current_map->x_res ||
		tex->height + y > state->current_map->y_res)
		return (0);
	while (yp < tex->height)
	{
		offset = ((yp + y) * state->frame.size_line) +
				(x * state->frame.bpp / 8);
		t_offset = yp * tex->size_line;
		ft_memcpy(state->frame.image_data + offset, tex->data_ptr + t_offset,
				tex->width * state->frame.bpp / 8);
		yp++;
	}
	return (1);
}
