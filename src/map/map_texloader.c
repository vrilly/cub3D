/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_texloader.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 18:03:50 by tjans         #+#    #+#                 */
/*   Updated: 2020/03/02 19:07:13 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	verify_file(char *arg)
{
	int		fd;
	int		ret;
	char	magic[9];

	fd = open(arg, O_RDONLY);
	ret = 1;
	if (!fd)
		return (0);
	if (read(fd, magic, 9) != 9)
		ret = 0;
	if (ft_strncmp(magic, "/* XPM */", 9) != 0)
		ret = 0;
	close(fd);
	return (ret);
}

int	load_texture(char *arg, t_texture *dst, void *mlx)
{
	if (!verify_file(arg))
		return (0);
	dst->img_ptr = mlx_xpm_file_to_image(mlx, arg, &dst->width, &dst->height);
	dst->data_ptr = mlx_get_data_addr(dst->img_ptr, &dst->bpp, &dst->size_line,
			&dst->endian);
	return (dst->img_ptr != NULL);
}
