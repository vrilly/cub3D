/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   engine.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 19:43:56 by tjans         #+#    #+#                 */
/*   Updated: 2020/03/01 20:21:41 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_sprite_engine(t_game *state, t_map *map)
{
	state->spr.zbuffer = ft_calloc(sizeof(double), (size_t)map->x_res);
	state->spr.sprites = ft_calloc(sizeof(t_sprite *), 128);
	if (!state->spr.zbuffer || !state->spr.sprites)
		safe_exit(state, -1, "malloc fail");
}

void		add_sprite(t_game *state, double x, double y)
{
	t_sprite_engine	*engine;

	engine = &state->spr;
	if (engine->num_sprites >= 128)
		return ;
	engine->sprites[engine->num_sprites] = ft_calloc(1, sizeof(t_sprite));
	if (!engine->sprites[engine->num_sprites])
		safe_exit(state, -1, "malloc fail");
	engine->sprites[engine->num_sprites]->x_pos = x + 0.5;
	engine->sprites[engine->num_sprites]->y_pos = y + 0.5;
	engine->sprites[engine->num_sprites]->texture =
		&state->current_map->texture_sprite;
	engine->num_sprites++;
}

static void	calc_sprite_distance(t_game *state)
{
	int			i;
	t_vectors	*vec;
	t_sprite	*spr;

	i = 0;
	vec = &state->vec;
	while (i < state->spr.num_sprites)
	{
		spr = state->spr.sprites[i];
		state->spr.sprite_order[i] = i;
		spr->distance = ((vec->pos_x - spr->x_pos) * (vec->pos_x - spr->x_pos)
				+ (vec->pos_y - spr->y_pos) * (vec->pos_y - spr->y_pos));
		i++;
	}
}

void		render_sprites(t_game *state)
{
	calc_sprite_distance(state);
	sort_sprites(&state->spr);
	cast_sprites(state);
}
