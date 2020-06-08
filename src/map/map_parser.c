/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parser.c                                       :+:    :+:            */
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
	char	infostr[128];

	ft_snprintf(infostr, 128, "Map info: %s", arg);
	ftlog(LOG_INFO, infostr);
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
		return ((int)set_error(state, "Resolution invalid."));
	return (1);
}

int	map_parse_col_ceiling(char *arg, t_game *state)
{
	if (!get_color_val(arg, &state->current_map->color_floor))
		return ((int)set_error(state, "Color invalid."));
	return (1);
}

int	map_parse_col_floor(char *arg, t_game *state)
{
	if (!get_color_val(arg, &state->current_map->color_ceiling))
		return ((int)set_error(state, "Color invalid."));
	return (1);
}
