/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 18:08:12 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/04 05:51:15 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "renderer.h"

static void	vert_line(int x, t_game *state, t_draw_p *params)
{
	t_vertline	c;

	c.i = params->line_start;
	c.step = 1.0 * params->texture->height / params->line_height;
	c.t_y = (params->line_start - state->current_map->y_res / 2 +
			params->line_height / 2) * c.step;
	c.t_x = (int)(state->vis.wall_x * (double)params->texture->width);
	if ((state->rcp.side == 0 && state->rcp.rc_dir_x > 0) ||
			(state->rcp.side == 1 && state->rcp.rc_dir_y < 0))
		c.t_x = params->texture->width - c.t_x - 1;
	while (c.i < params->line_end)
	{
		c.tex_pixel = params->texture->data_ptr + c.t_x * 4 + (((int)c.t_y &
				(params->texture->height - 1)) *
				params->texture->size_line);
		c.data_addr = state->frame.image_data
			+ (c.i * state->frame.size_line)
			+ (x * (state->frame.bpp / 8));
		*(unsigned int*)c.data_addr = *(unsigned int*)c.tex_pixel;
		c.t_y += c.step;
		c.i++;
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
		calc_params(state, x);
		calc_raycaster_step(state);
		calc_dda(state);
		calc_vert_line(state);
		calc_wallx(state);
		vert_line(x, state, &state->vis);
		state->spr.zbuffer[x] = state->rcp.walldist;
		x++;
	}
	render_sprites(state);
	end_frame(state);
	mlx_do_sync(state->mlx_ptr);
	return (1);
}
