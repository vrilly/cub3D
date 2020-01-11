/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_reader_seq.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 19:13:58 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/11 17:11:09 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "cub3d.h"
#include "map_seq.h"

int	map_reader_seq_resolution(t_fdstream *fs, t_map *map)
{
	char	*res_line;
	char	*res_line_next;
	int		res;

	if (fd_readline(fs, &res_line) != 1)
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

int	map_reader_seq_textures(t_fdstream *fs, t_map *map)
{
}
