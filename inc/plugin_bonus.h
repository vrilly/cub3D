/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plugin_bonus.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 12:00:00 by tjans         #+#    #+#                 */
/*   Updated: 2020/05/05 12:00:00 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLUGIN_BONUS_H
# define PLUGIN_BONUS_H

typedef struct s_game	t_game;

/*
** Plugin metadata.
** At this moment only contains the plugin name
** In the future it will be able to hold a bit more stuff like configuration
** and more metadata
*/

typedef struct			s_plugininfo
{
	char	*name;
}						t_plugininfo;

/*
** Plugin struct
** Contains all hooks plugins can provide
*/

typedef struct			s_plugin
{
	void			*dl_handle;
	void			*pl_state;

	t_plugininfo	*info;

	int				(*setup_hook)(void **pl_state);
	int				(*frame_hook)(t_game *state, void *pl_state);
	int				(*map_hook)(t_game *state, char *prefix, char *arg,
			void *pl_state);
	int				(*update_hook)(t_game *state, void *pl_state);
	int				(*pregame_hook)(t_game *state, void *pl_state);
}						t_plugin;

/*
** Linked list for all loaded plugins.
*/

typedef struct			s_pluginlist
{
	t_plugin			*plugin;
	struct s_pluginlist	*next;
}						t_pluginlist;

/*
** Loads config.txt in plugins/ and loads all dynamic libraries
** Upon loading it initializes struct, resolves symbols for hooks and
** adds it to the linked list in the game struct
*/

enum e_cub_error		init_plugins(t_game *state);

/*
** Functions which iterates through the loaded plugins and executes the hooks
** Error handling here is very basic. Could've been done better tbh
*/

void					execute_frame_hook(t_game *state);
void					execute_pregame_hook(t_game *state);
int						execute_map_hook(t_game *state, char *prefix,
		char *arg);

#endif
