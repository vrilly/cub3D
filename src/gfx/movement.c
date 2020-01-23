/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 17:24:54 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/23 17:25:53 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	forwards(t_game *state)
{
	state->vec.pos_x += state->vec.dir_x * 0.20;
	state->vec.pos_y += state->vec.dir_y * 0.20;
}

void	backwards(t_game *state)
{
	state->vec.pos_x -= state->vec.dir_x * 0.20;
	state->vec.pos_y -= state->vec.dir_y * 0.20;
}
