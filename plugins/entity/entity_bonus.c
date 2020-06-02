/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   entity_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 12:00:00 by tjans         #+#    #+#                 */
/*   Updated: 2020/05/05 12:00:00 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "entity_bonus.h"

t_plugininfo	g_plugininfo = {
	.name = "Entity handler"
};

int				setup(t_pluginstate **ps_ptr)
{
	t_pluginstate	*state;

	state = ft_calloc(1, sizeof(t_pluginstate));
	*ps_ptr = state;
	return (state != NULL);
}

int				map_hook(t_game *state, char *prefix, char *arg,
		t_pluginstate *ps)
{
	if (ft_strncmp(prefix, "DEF_ENTITY", 10) == 0)
		return (define_entity(state, ps, arg));
	return (0);
}

int				spawn_hook(t_game *state, char c, t_coordinate coord,
		t_pluginstate *ps)
{
	if (!(c >= 'A' && c <= 'D'))
		return (0);
	if (!spawn_entity(state, c, coord, ps))
	{
		ft_printf("[WARN] Tried to use uninitialized entity\n");
		ft_printf("[WARN] slot: %c x: %d y: %d\n", c, coord.split_int.x,
				coord.split_int.y);
	}
	return (1);
}
