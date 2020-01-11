/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_texloader.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 18:03:50 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/11 18:08:15 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_texloader.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 16:38:31 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/11 18:03:16 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map_seq.h"

int	load_texture(const char *ti, t_fdstream *fs, t_texture *dst, void *mlx)
{
	char	*line;
	int		ti_len;

	ti_len = ft_strlen(ti);
	if (fd_readline(fs, &line) != 1)
		return (0);
	if (ft_strncmp(line, ti, ti_len))
		return (0);
	line = ft_strchr(line, ' ');
	if (!*line || !*(line + 1))
		return (0);
	line++;
	dst->data = mlx_xpm_file_to_image(mlx, line, &dst->width, &dst->height);
	return (dst->data != NULL);
}
