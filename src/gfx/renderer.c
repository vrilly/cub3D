/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 18:08:12 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/20 14:38:32 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	vert_line(int x, t_game *state, t_draw_p *params)
{
	int		i;
	char	*data_addr;

	i = params->line_start;
	while (i < params->line_end)
	{
		data_addr = state->frame.image_data
			+ (i * state->frame.size_line)
			+ (x * (state->frame.bpp / 8));
		if (state->rcp.side)
			*(unsigned int*)data_addr = 0xFF;
		else
			*(unsigned int*)data_addr = 0xFF / 2;
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
