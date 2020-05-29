/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plugin.h                                           :+:    :+:            */
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

typedef struct			s_plugininfo
{
	char	*name;
}						t_plugininfo;

typedef struct			s_plugin
{
	void			*dl_handle;
	void			*pl_state;

	t_plugininfo	*info;

	int				(*setup_hook)(void **pl_state);
	int				(*frame_hook)(t_game *state, void *pl_state);
	int				(*map_hook)(t_game *state, void *pl_state);
	int				(*update_hook)(t_game *state, void *pl_state);
	int				(*pregame_hook)(t_game *state, void *pl_state);
}						t_plugin;

typedef struct			s_pluginlist
{
	t_plugin			*plugin;
	struct s_pluginlist	*next;
}						t_pluginlist;

enum e_cub_error		init_plugins(t_game *state);
void					execute_frame_hook(t_game *state);
void					execute_pregame_hook(t_game *state);

#endif
