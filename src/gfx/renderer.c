/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 18:08:12 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/21 19:32:52 by tjans         ########   odam.nl         */
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
	int		t_x;

	i = params->line_start;
	step = 1.0 * params->texture->height / params->line_height;
	t_y = (params->line_start - state->current_map->y_res / 2 +
			params->line_height / 2) * step;
	t_x = state->vis.wall_x * (double)params->texture->width;
	if ((state->rcp.side == 0 && state->rcp.rc_dir_x > 0) ||
			(state->rcp.side == 1 && state->rcp.rc_dir_y < 0))
		t_x = params->texture->width - t_x - 1;
	while (i < params->line_end)
	{
		tex_pixel = params->texture->data_ptr + t_x * 4 + (((int)t_y & (params->texture->
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
	movement_loop(state);
	start_frame(state);
	while (x < state->current_map->x_res)
	{
		precalc(state, x);
		calc_step(state);
		calc_dda(state);
		prerendercalc(state);
		wallx_calc(state);
		vert_line(x, state, &state->vis);
		x++;
	}
	end_frame(state);
	mlx_do_sync(state->mlx_ptr);
	return (1);
}
