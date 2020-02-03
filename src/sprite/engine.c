/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   engine.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 19:43:56 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/03 22:31:41 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_sprite(t_game *state, double x, double y)
{
	t_sprite_engine	*engine;

	engine = &state->spr;
	engine->sprites[engine->num_sprites]->x_pos = x;
	engine->sprites[engine->num_sprites]->y_pos = y;
	engine->sprites[engine->num_sprites]->texture =
		&state->current_map->texture_sprite;
	engine->num_sprites++;
}

void		init_sprite_engine(t_game *state)
{
	state->spr.zbuffer = ft_calloc(sizeof(double), state->current_map->x_res);
	state->spr.sprites_size = 8;
	state->spr.sprites = ft_calloc(sizeof(t_sprite), 8);
}

void		render_sprites(t_game *state)
{
	sort_sprites(&state->spr);
}
