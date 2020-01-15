/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 18:08:12 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/13 20:54:26 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	vert_line(int x, t_game *state, t_draw_p *params)
{
	int	i;

	i = params->line_start;
	while (i < params->line_end)
	{
		mlx_pixel_put(state->mlx_ptr, state->window,
				x, i, 0x000000FF);
		i++;
	}
}

int			render_frame(t_game *state)
{
	int	x;

	x = 0;
	while (x < state->current_map->x_res)
	{
		precalc(state, x);
		calc_step(state);
		calc_dda(state);
		prerendercalc(state);
		vert_line(x, state, &state->vis);
		x++;
	}
	mlx_do_sync(state->mlx_ptr);
	return (1);
}
