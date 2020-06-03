/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hud_bonus.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 12:00:00 by tjans         #+#    #+#                 */
/*   Updated: 2020/05/05 12:00:00 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUD_BONUS_H
# define HUD_BONUS_H
# include "libplugin_bonus.h"

# define COLOR_OOB		0x00666666
# define COLOR_EMPTY	0x00000000
# define COLOR_WALL		0x00FFFFFF
# define COLOR_ITEM		0x00FF0000

typedef struct	s_pluginstate
{
	t_texture	*fb;
	int			enabled;
}				t_pluginstate;

void			update(t_game *map, t_texture *fb);

#endif
