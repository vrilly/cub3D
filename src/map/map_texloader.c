/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_texloader.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 18:03:50 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/04 10:36:47 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	load_texture(const char *ti, t_fdstream *fs, t_texture *dst, void *mlx)
{
	char	*line;
	char	*line_org;
	int		ti_len;

	ti_len = ft_strlen(ti);
	if (fd_readline_sb(fs, &line) != 1)
		return (0);
	line_org = line;
	if (ft_strncmp(line, ti, ti_len))
		return (0);
	line = ft_strchr(line, ' ');
	if (!*line || !*(line + 1))
		return (0);
	line++;
	dst->img_ptr = mlx_xpm_file_to_image(mlx, line, &dst->width, &dst->height);
	dst->data_ptr = mlx_get_data_addr(dst->img_ptr, &dst->bpp, &dst->size_line,
			&dst->endian);
	free(line_org);
	return (dst->img_ptr != NULL);
}
