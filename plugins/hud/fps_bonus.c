/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fps_bonus.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 12:00:00 by tjans         #+#    #+#                 */
/*   Updated: 2020/05/05 12:00:00 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hud_bonus.h"

int	get_fps(t_pluginstate *ps)
{
	clock_t	newtime;
	clock_t	deltatime;

	newtime = clock();
	deltatime = newtime - ps->fps_timer;
	ps->fps_timer = newtime;
	if (deltatime > 0)
		return ((int)(CLOCKS_PER_SEC / deltatime));
	return (0);
}
