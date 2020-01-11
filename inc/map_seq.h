/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_seq.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 19:15:01 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/10 17:54:53 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_SEQ_H
# define MAP_SEQ_H

int	map_reader_seq_resolution(t_fdstream *fs, t_map *map);
int	map_reader_seq_textures(t_fdstream *fs, t_map *map);

#endif
