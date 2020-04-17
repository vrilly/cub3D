/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_seq.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 19:15:01 by tjans         #+#    #+#                 */
/*   Updated: 2020/03/01 17:50:21 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "cub3d.h"

typedef struct			s_mapbuffer
{
	char				*line;
	int					line_size;
	int					str_size;
	int					line_size_max;
	int					lines;
	struct s_mapbuffer	*next;
}						t_mapbuffer;

typedef struct			s_mplookup
{
	char	*prefix;
	int		(*func)(char *arg, t_game *state);
}						t_mplookup;

t_mplookup				*find_func(char *prefix);

t_mapbuffer				*mbuf_create(char *line, int line_size);
void					mbuf_append(t_mapbuffer *root, t_mapbuffer *new);
enum e_map_tile_type	*mbuf_finalize(t_mapbuffer *root, int *map_height);
void					mbuf_destroy(t_mapbuffer *root);
int						map_reader_seq_resolution(char *arg, t_game *state);
int						map_reader_seq_tno(char *arg, t_game *state);
int						map_reader_seq_tso(char *arg, t_game *state);
int						map_reader_seq_twe(char *arg, t_game *state);
int						map_reader_seq_tea(char *arg, t_game *state);
int						map_reader_seq_ts(char *arg, t_game *state);
int						load_texture(char *arg, t_texture *dst, void *mlx);
int						get_color_val(char *arg,
		unsigned int *dst);
int						map_reader_seq_ceiling_colour(char *arg, t_game *state);
int						map_reader_seq_floor_colour(char *arg, t_game *state);
int						map_flip(t_map *map, t_game *state);
int						map_comment(char *arg);

#endif
