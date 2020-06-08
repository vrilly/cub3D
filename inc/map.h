/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 19:15:01 by tjans         #+#    #+#                 */
/*   Updated: 2020/03/01 17:50:21 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** The map part of my project really needs refactoring.
** But i plainly refuse :(
*/

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
	int		used;
}						t_mplookup;

t_mplookup				*find_func(char *prefix);
int						fd_readline_sb(t_fdstream *file, char **line);

t_mapbuffer				*mbuf_create(char *line, int line_size);
void					mbuf_append(t_mapbuffer *root, t_mapbuffer *new);
enum e_map_tile_type	*mbuf_finalize(t_mapbuffer *root, int *map_height);
void					mbuf_destroy(t_mapbuffer *root);

int						map_parse_resolution(char *arg, t_game *state);
int						map_parse_tex_no(char *arg, t_game *state);
int						map_parse_tex_so(char *arg, t_game *state);
int						map_parse_tex_we(char *arg, t_game *state);
int						map_parse_tex_ea(char *arg, t_game *state);
int						map_parse_tex_sprite(char *arg, t_game *state);
int						map_parse_col_floor(char *arg, t_game *state);
int						map_parse_col_ceiling(char *arg, t_game *state);
int						map_parse_comment(char *arg);

int						load_texture(t_game *state,
		char *arg, t_texture *dst, void *mlx);
int						get_color_val(char *arg,
		unsigned int *dst);
int						map_flip(t_map *map, t_game *state);
int						verify_map(t_map *map, t_game *state);

#endif
