/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   entity_bonus.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 12:00:00 by tjans         #+#    #+#                 */
/*   Updated: 2020/05/05 12:00:00 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_BONUS_H
# define ENTITY_BONUS_H
# include "libplugin_bonus.h"

typedef enum	e_type
{
	EMPTY_SLOT,
	CREATURE,
	ITEM
}				t_type;

typedef struct	s_entitytype
{
	t_texture	*texture;

	char		name[16];
	t_type		type;
	int			collisions_enabled;
	int			initial_hp;
}				t_entitytype;

typedef struct	s_entity
{
	t_entitytype	*type;
	t_sprite		*sprite;

	int				health_points;
	void			*ai_hook;
	void			*ai_parameters;
}				t_entity;

typedef struct	s_pluginstate
{
	t_entitytype	custom_entities[4];
	t_entity		entities[64];
	int				num_entities;
}				t_pluginstate;

int				define_entity(t_game *state, t_pluginstate *ps, char *arg);
int				spawn_entity(t_game *state, char c, t_coordinate coord,
		t_pluginstate *ps);
#endif
