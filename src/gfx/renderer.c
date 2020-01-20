/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 18:08:12 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/20 18:42:17 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	vert_line(int x, t_game *state, t_draw_p *params)
{
	int		i;
	char	*tex_pixel;
	char	*data_addr;
	double	step;
	double	t_y;

	i = params->line_start;
	step = 1.0 * params->texture->height / params->line_height;
	t_y = (params->line_start - state->current_map->y_res / 2 +
			params->line_height / 2) * step;
	while (i < params->line_end)
	{
		tex_pixel = params->texture->data_ptr + (((int)t_y & (params->texture->
					height - 1)) * params->texture->size_line);
		data_addr = state->frame.image_data
			+ (i * state->frame.size_line)
			+ (x * (state->frame.bpp / 8));
		if (state->rcp.side)
			*(unsigned int*)data_addr = *(unsigned int*)tex_pixel;
		else
			*(unsigned int*)data_addr = *(unsigned int*)tex_pixel;
		t_y += step;
		i++;
	}
}

int			render_frame(t_game *state)
{
	int	x;

	x = 0;
	start_frame(state);
	while (x < state->current_map->x_res)
	{
		precalc(state, x);
		calc_step(state);
		calc_dda(state);
		prerendercalc(state);
		vert_line(x, state, &state->vis);
		x++;
	}
	end_frame(state);
	mlx_do_sync(state->mlx_ptr);
	return (1);
}
