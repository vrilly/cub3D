/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_reader_seq.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 19:13:58 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/27 18:47:19 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	map_reader_seq_resolution(char *arg, t_game *state)
{
	int	res;

	res = ft_atoi(arg);
	state->current_map->x_res = res;
	arg = ft_strchr(arg, ' ');
	res = ft_atoi(arg);
	state->current_map->y_res = res;
	if (state->current_map->x_res < 1 || state->current_map->y_res < 1)
		return (0);
	return (1);
}

int	map_reader_seq_floor_colour(char *arg, t_game *state)
{
	return (get_color_val(arg, &state->current_map->color_floor));
}

int	map_reader_seq_ceiling_colour(char *arg, t_game *state)
{
	return (get_color_val(arg, &state->current_map->color_ceiling));
}
