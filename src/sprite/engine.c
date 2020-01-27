/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   engine.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 19:43:56 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/23 20:03:55 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sprite_engine(t_game *state)
{
	state->spr.zbuffer = ft_calloc(sizeof(double), state->current_map->x_res);
	state->spr.sprites_size = 8;
	state->spr.sprites = ft_calloc(sizeof(t_sprite), 8);
}

void	add_sprite(t_game *state, t_texture *tex, double x, double y)
{
	static t_sprite_engine	*engine = &state->spr;

	engine->sprites[engine->num_sprites]->x_pos = x;
	engine->sprites[engine->num_sprites]->y_pos = y;
	engine->sprites[engine->num_sprites]->texture = tex;
	engine->num_sprites++;
}
