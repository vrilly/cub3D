/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 12:00:00 by tjans         #+#    #+#                 */
/*   Updated: 2020/05/05 12:00:00 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H
# include "cub3d.h"
# include "plugin.h"

# define COLOR_OOB		0xFF666666
# define COLOR_EMPTY	0x00000000
# define COLOR_WALL		0xFFFFFFFF
# define COLOR_ITEM		0xFFFF0000

typedef struct	s_pluginstate
{
	t_texture	*fb;
	int			enabled;
}				t_pluginstate;

void			update(t_game *map, t_texture *fb);

#endif
