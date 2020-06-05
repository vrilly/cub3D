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

int		execute_map_hook(t_game *state, char *prefix, char *arg)
{
	t_pluginlist	*list;
	int				ret;

	if (state->plugins == NULL)
		return (1);
	list = state->plugins;
	while (list)
	{
		if (list->plugin->map_hook != NULL)
		{
			ret = (*list->plugin->map_hook)(state, prefix, arg,
					list->plugin->pl_state);
			if (ret == -1)
				safe_exit(state, PLUGIN_FAIL, "Map hook failed.");
			if (ret == 1)
				return (1);
		}
		list = list->next;
	}
	ft_printf("[INFO] Unhandled map element. Prefix: %.*s\n",
			ft_strclen(prefix, ' '), prefix);
	return (1);
}

void	execute_spawn_hook(t_game *state, char c, int x, int y)
{
	t_pluginlist	*list;
	int				ret;
	t_coordinate	coord;

	coord.split_int.x = x;
	coord.split_int.y = y;
	if (state->plugins == NULL)
		return ;
	list = state->plugins;
	while (list)
	{
		if (list->plugin->spawn_hook != NULL)
		{
			ret = (*list->plugin->spawn_hook)(state, c, coord,
					list->plugin->pl_state);
			if (ret == -1)
				safe_exit(state, PLUGIN_FAIL, "Spawn hook failed.");
			if (ret == 1)
				return ;
		}
		list = list->next;
	}
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
			if (!(*list->plugin->pregame_hook)(state, list->plugin->pl_state))
			{
				ft_fprintf(2, "[ERROR] Plugin %s failed to initialize\n",
						list->plugin->info->name);
				exit(PLUGIN_FAIL);
			}
		list = list->next;
	}
}
