/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_reader_seq.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 19:13:58 by tjans         #+#    #+#                 */
/*   Updated: 2020/03/04 19:22:06 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	map_parse_comment(char *arg)
{
	static int	first_comment = 1;

	if (first_comment)
	{
		first_comment = 0;
		ftlog(LOG_INFO, "Map info!");
	}
	ftlog(LOG_INFO, arg);
	return (1);
}

int	map_parse_resolution(char *arg, t_game *state)
{
	int	res;

	res = ft_atoi(arg);
	state->current_map->x_res = res;
	arg = ft_strchr(arg, ' ');
	if (!arg)
		return (0);
	res = ft_atoi(arg);
	state->current_map->y_res = res;
	if (state->current_map->x_res < 1 || state->current_map->y_res < 1)
		return (0);
	return (1);
}

int	map_parse_col_ceiling(char *arg, t_game *state)
{
	return (get_color_val(arg, &state->current_map->color_floor));
}

int	map_parse_col_floor(char *arg, t_game *state)
{
	return (get_color_val(arg, &state->current_map->color_ceiling));
}
