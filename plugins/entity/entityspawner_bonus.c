/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   entityspawner_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 12:00:00 by tjans         #+#    #+#                 */
/*   Updated: 2020/05/05 12:00:00 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "entity_bonus.h"

static t_sprite	*inject_sprite(t_game *state, int x, int y, t_texture *tex)
{
	t_sprite_engine	*engine;

	engine = &state->spr;
	if (engine->num_sprites >= 128)
		return (NULL);
	engine->sprites[engine->num_sprites] = ft_calloc(1, sizeof(t_sprite));
	if (!engine->sprites[engine->num_sprites])
		return (NULL);
	engine->sprites[engine->num_sprites]->x_pos = x + 0.5;
	engine->sprites[engine->num_sprites]->y_pos = y + 0.5;
	engine->sprites[engine->num_sprites]->texture = tex;
	engine->num_sprites++;
	return (engine->sprites[engine->num_sprites - 1]);
}

int				spawn_entity(t_game *state, char c,
		t_coordinate coord, t_pluginstate *ps)
{
	t_entitytype	*et;
	t_entity		*entity;
	t_sprite		*spr;

	if (ps->num_entities >= 128)
		return (0);
	et = &ps->custom_entities[c - 'A'];
	if (et->type == EMPTY_SLOT)
		return (0);
	spr = inject_sprite(state, coord.split_int.x, coord.split_int.y,
			et->texture);
	if (!spr)
		return (0);
	entity = &ps->entities[ps->num_entities];
	entity->health_points = et->initial_hp;
	entity->type = et;
	entity->sprite = spr;
	return (1);
}
