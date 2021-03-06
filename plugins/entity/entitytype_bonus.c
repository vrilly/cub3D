/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   entitytype_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 12:00:00 by tjans         #+#    #+#                 */
/*   Updated: 2020/05/05 12:00:00 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "entity_bonus.h"

static int	parse_data(t_game *state, char *arg, t_entitytype *et)
{
	et->type = CREATURE;
	if (ft_strclen(arg + 1, ' ') > 16)
		return (0);
	ft_strlcpy(et->name, arg + 1, ft_strclen(arg + 1, ' ') + 1);
	arg = ft_strchr(arg, ' ');
	if (arg)
		arg = ft_strchr(arg + 1, ' ');
	if (!arg || !*(arg + 1))
		return (0);
	et->collisions_enabled = (*(arg + 1) == '1');
	arg = ft_strchr(arg + 1, ' ');
	if (!arg || !*(arg + 1))
		return (0);
	et->initial_hp = ft_atoi(arg + 1);
	arg = ft_strchr(arg + 1, ' ');
	et->texture = ft_calloc(1, sizeof(t_texture));
	if (!arg || !*(arg + 1) || et->initial_hp < 0 || !et->texture)
		return (0);
	return (load_texture_lplugin(state, arg + 1, et->texture, state->mlx_ptr));
}

int			define_entity(t_game *state, t_pluginstate *ps, char *arg)
{
	t_entitytype	*et;
	int				slot;

	slot = ft_atoi(arg);
	arg = ft_strchr(arg, ' ');
	if (slot > 3 || slot < 0 || !arg)
		return (-1);
	et = &ps->custom_entities[slot];
	if (et->texture || !parse_data(state, arg, et))
		return (-1);
	return (1);
}

int			define_item(t_pluginstate *ps, char *arg)
{
	t_entitytype	*et;
	int				slot;
	int				dmg;

	slot = ft_atoi(arg);
	arg = ft_strchr(arg, ' ');
	et = &ps->custom_entities[slot];
	if (slot > 3 || slot < 0 || !arg || et->type == EMPTY_SLOT)
		return (-1);
	dmg = ft_atoi(arg);
	if (dmg > 100 || dmg < -100)
		return (-1);
	et->type = ITEM;
	et->collide_damage = dmg;
	return (1);
}

int			define_player_entity(t_pluginstate *ps, char *arg)
{
	ps->player_hp = ft_atoi(arg);
	return (ps->player_hp > 0 && ps->player_hp <= 100);
}
