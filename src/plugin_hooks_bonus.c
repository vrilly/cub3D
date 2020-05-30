/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plugin_hooks_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 12:00:00 by tjans         #+#    #+#                 */
/*   Updated: 2020/05/05 12:00:00 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		execute_map_hook(t_game *state)
{
	t_pluginlist	*list;

	if (state->plugins == NULL)
		return (1);
	list = state->plugins;
	while (list)
	{
		if (list->plugin->map_hook != NULL)
			return (*list->plugin->map_hook)(state, list->plugin->pl_state);
		list = list->next;
	}
	return (1);
}

void	execute_frame_hook(t_game *state)
{
	t_pluginlist *list;

	if (state->plugins == NULL)
		return ;
	list = state->plugins;
	while (list)
	{
		if (list->plugin->update_hook != NULL)
			(*list->plugin->update_hook)(state, list->plugin->pl_state);
		if (list->plugin->frame_hook != NULL)
			(*list->plugin->frame_hook)(state, list->plugin->pl_state);
		list = list->next;
	}
}

void	execute_pregame_hook(t_game *state)
{
	t_pluginlist *list;

	if (state->plugins == NULL)
		return ;
	list = state->plugins;
	while (list)
	{
		if (list->plugin->pregame_hook != NULL)
			(*list->plugin->pregame_hook)(state, list->plugin->pl_state);
		list = list->next;
	}
}
