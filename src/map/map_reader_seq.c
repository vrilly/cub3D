/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_reader_seq.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 19:13:58 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/04 10:36:30 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	map_reader_seq_resolution(t_fdstream *fs, t_map *map, t_game *state)
{
	char	*res_line;
	char	*res_line_next;
	int		res;

	(void)state;
	if (fd_readline_sb(fs, &res_line) != 1)
		return (0);
	if (*res_line != 'R')
		return (0);
	res_line_next = ft_strchr(res_line, ' ');
	if (res_line_next == NULL || res_line_next + 1 == NULL)
		return (0);
	res = ft_atoi(res_line_next + 1);
	map->x_res = res;
	res_line_next = ft_strchr(res_line_next + 1, ' ');
	if (res_line_next == NULL || res_line_next + 1 == NULL)
		return (0);
	res = ft_atoi(res_line_next + 1);
	map->y_res = res;
	if (map->x_res < 1 || map->y_res < 1)
		return (0);
	free(res_line);
	return (1);
}

int	map_reader_seq_textures(t_fdstream *fs, t_map *map, t_game *state)
{
	int	success;

	success = load_texture("NO", fs, &map->texture_north, state->mlx_ptr);
	success += load_texture("SO", fs, &map->texture_south, state->mlx_ptr);
	success += load_texture("WE", fs, &map->texture_west, state->mlx_ptr);
	success += load_texture("EA", fs, &map->texture_east, state->mlx_ptr);
	success += load_texture("S", fs, &map->texture_sprite, state->mlx_ptr);
	return (success == 5);
}

int	map_reader_seq_colors(t_fdstream *fs, t_map *map, t_game *state)
{
	int success;

	(void)state;
	success = get_color_val('F', fs, &map->color_floor);
	success += get_color_val('C', fs, &map->color_ceiling);
	return (success == 2);
}
