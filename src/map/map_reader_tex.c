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

int	map_reader_seq_tno(char *arg, t_game *state)
{
	return (load_texture(state, arg, &state->current_map->texture_north,
			state->mlx_ptr));
}

int	map_reader_seq_tso(char *arg, t_game *state)
{
	return (load_texture(state, arg, &state->current_map->texture_south,
			state->mlx_ptr));
}

int	map_reader_seq_twe(char *arg, t_game *state)
{
	return (load_texture(state, arg, &state->current_map->texture_west,
			state->mlx_ptr));
}

int	map_reader_seq_tea(char *arg, t_game *state)
{
	return (load_texture(state, arg, &state->current_map->texture_east,
			state->mlx_ptr));
}

int	map_reader_seq_ts(char *arg, t_game *state)
{
	return (load_texture(state, arg, &state->current_map->texture_sprite,
			state->mlx_ptr));
}
