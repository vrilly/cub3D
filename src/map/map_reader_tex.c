/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_reader_tex.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 18:30:47 by tjans         #+#    #+#                 */
/*   Updated: 2020/03/01 17:48:51 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <map.h>

int	map_parse_tex_no(char *arg, t_game *state)
{
	return (load_texture(state, arg, &state->current_map->texture_north,
			state->mlx_ptr));
}

int	map_parse_tex_so(char *arg, t_game *state)
{
	return (load_texture(state, arg, &state->current_map->texture_south,
			state->mlx_ptr));
}

int	map_parse_tex_we(char *arg, t_game *state)
{
	return (load_texture(state, arg, &state->current_map->texture_west,
			state->mlx_ptr));
}

int	map_parse_tex_ea(char *arg, t_game *state)
{
	return (load_texture(state, arg, &state->current_map->texture_east,
			state->mlx_ptr));
}

int	map_parse_tex_sprite(char *arg, t_game *state)
{
	return (load_texture(state, arg, &state->current_map->texture_sprite,
			state->mlx_ptr));
}
