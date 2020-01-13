/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 18:08:12 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/13 20:18:52 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			render_frame(t_game *state)
{
	int	x;

	x = 0;
	while (x < state->current_map->x_res)
	{
		precalc(state, x);
		calc_step(state);
		x++;
	}
	mlx_do_sync(state->mlx_ptr);
	return (1);
}
