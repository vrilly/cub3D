/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plugin.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 12:00:00 by tjans         #+#    #+#                 */
/*   Updated: 2020/05/05 12:00:00 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

enum e_cub_error	init_plugins(t_game *state)
{
	(void)state;
	ftlog(LOG_INFO, "Plugin support disabled.");
	return (NO_ERROR);
}
