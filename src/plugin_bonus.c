/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plugin_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 12:00:00 by tjans         #+#    #+#                 */
/*   Updated: 2020/05/05 12:00:00 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <dlfcn.h>
#include "cub3d.h"

static void			messy_error(char *err)
{
	ft_fprintf(2, "Unhandled plugin error: %s\n", err);
	exit(-1);
}

static t_plugin		*load_plugin(char *path)
{
	t_plugin	*plugin;

	plugin = malloc(sizeof(t_plugin));
	if (plugin == NULL)
		messy_error("malloc fail");
	plugin->dl_handle = dlopen(path, RTLD_NOW);
	if (!plugin->dl_handle)
	{
		ft_fprintf(2, "dlopen result: %s\n", dlerror());
		messy_error("dlopen fail");
	}
	plugin->info = dlsym(plugin->dl_handle, "g_plugininfo");
	plugin->setup_hook = dlsym(plugin->dl_handle, "setup");
	if (!plugin->info || !plugin->setup_hook)
		messy_error("invalid plugin");
	plugin->frame_hook = dlsym(plugin->dl_handle, "frame_hook");
	plugin->map_hook = dlsym(plugin->dl_handle, "map_hook");
	plugin->pregame_hook = dlsym(plugin->dl_handle, "pregame_hook");
	plugin->update_hook = dlsym(plugin->dl_handle, "update_hook");
	if (!(*plugin->setup_hook)(&plugin->pl_state))
		messy_error(plugin->info->name);
	ft_printf("[INFO] Loaded plugin: %s\n", plugin->info->name);
	return (plugin);
}

static void			append_plugin(t_game *state, t_plugin *plugin)
{
	t_pluginlist *lst;

	if (!state->plugins)
	{
		state->plugins = ft_calloc(1, sizeof(t_pluginlist));
		state->plugins->plugin = plugin;
	}
	else
	{
		lst = state->plugins;
		while (lst->next)
			lst = lst->next;
		lst->next = ft_calloc(1, sizeof(t_pluginlist));
		lst->next->plugin = plugin;
	}
}

enum e_cub_error	init_plugins(t_game *state)
{
	t_fdstream		*fd;
	char			*line;

	fd = fd_open("plugins/config.txt", O_RDONLY);
	if (!fd)
		return (NO_ERROR);
	while (fd_readline(fd, &line) == 1)
	{
		if (*line != '#' && *line)
			append_plugin(state, load_plugin(line));
		free(line);
	}
	free(line);
	fd_close(fd);
	free(fd);
	return (NO_ERROR);
}
