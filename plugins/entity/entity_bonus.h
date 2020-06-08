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

# define LIFEBAR_WIDTH		100
# define LIFEBAR_HEIGHT		16
# define LB_COLOR_EMPTY		0x00FF0000
# define LB_COLOR_FULL		0x0000FF00
# define LB_COLOR_BORDER	0x00000000

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
	int			collide_damage;
}				t_entitytype;

typedef struct	s_entity
{
	t_entitytype	*type;
	t_sprite		*sprite;

	int				health_points;
}				t_entity;

typedef struct	s_pluginstate
{
	t_entitytype	custom_entities[4];
	t_entity		entities[128];

	int				player_hp;
	int				num_entities;
}				t_pluginstate;

void			draw_player_lifebar(t_game *state, int player_hp);

int				define_player_entity(t_pluginstate *ps, char *arg);
int				define_entity(t_game *state, t_pluginstate *ps, char *arg);
int				define_item(t_pluginstate *ps, char *arg);
int				spawn_entity(t_game *state, char c, t_coordinate coord,
		t_pluginstate *ps);
#endif
