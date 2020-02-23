/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_seq.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 19:15:01 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/23 17:55:51 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "cub3d.h"

typedef struct			s_mapbuffer
{
	char				*line;
	int					line_size;
	int					line_size_max;
	int					lines;
	struct s_mapbuffer	*next;
}						t_mapbuffer;

t_mapbuffer				*mbuf_create(char *line, int line_size);
void					*mbuf_append(t_mapbuffer *root, t_mapbuffer *new);
enum e_map_tile_type	*mbuf_finalize(t_mapbuffer *root);
void					mbuf_destroy(t_mapbuffer *root);
int						map_reader_seq_resolution(t_fdstream *fs,
		t_map *map, t_game *state);
int						map_reader_seq_textures(t_fdstream *fs,
		t_map *map, t_game *state);
int						map_reader_seq_colors(t_fdstream *fs,
		t_map *map, t_game *state);
int						map_reader_seq_mapdata(t_fdstream *fs,
		t_map *map, t_game *state);
int						map_flip(t_fdstream *fs, t_map *map, t_game *state);

int						load_texture(const char *ti, t_fdstream *fs,
		t_texture *dst, void *mlx);
int						get_color_val(const char ti, t_fdstream *fs,
		unsigned int *dst);

#endif
