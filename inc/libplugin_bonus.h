/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libplugin_bonus.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 12:00:00 by tjans         #+#    #+#                 */
/*   Updated: 2020/05/05 12:00:00 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** This file is for the common utils plugin, only used for bonus
** All plugins should include this
*/

#ifndef LIBPLUGIN_BONUS_H
# define LIBPLUGIN_BONUS_H
# include "cub3d.h"
# include "plugin_bonus.h"

int	draw_tex(t_game *state, t_texture *tex, int x, int y);

#endif