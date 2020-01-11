/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_seq.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 19:15:01 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/11 18:03:27 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_SEQ_H
# define MAP_SEQ_H
# include "cub3d.h"

int	map_reader_seq_resolution(t_fdstream *fs, t_map *map, t_game *state);
int	map_reader_seq_textures(t_fdstream *fs, t_map *map, t_game *state);

int	load_texture(const char *ti, t_fdstream *fs, t_texture *dst, void *mlx);

#endif
