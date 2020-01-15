/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 19:42:49 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/15 19:51:23 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_game *state)
{
	t_vectors		*vec;
	const double	odirx = state->vec.dir_x;
	const double	oplanex = state->vec.plane_x;

	vec = &state->vec;
	vec->dir_x = odirx * cos(-5) - vec->dir_y * sin(-5);
	vec->dir_y = odirx * sin(-5) + vec->dir_y * cos(-5);
	vec->plane_x = oplanex * cos(-5) - vec->plane_y * sin(-5);
	vec->plane_y = oplanex * sin(-5) + vec->plane_y * sin(-5);
}
