/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   font_bonus.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 12:00:00 by tjans         #+#    #+#                 */
/*   Updated: 2020/05/05 12:00:00 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FONT_BONUS_H
# define FONT_BONUS_H
# include "libplugin_bonus.h"

# define CHAR_WIDTH 8
# define CHAR_HEIGHT 8

void	draw_string(t_game *state, char *str, int x, int y);

#endif
