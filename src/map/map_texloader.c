/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_texloader.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 18:03:50 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/27 18:38:17 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	load_texture(char *arg, t_texture *dst, void *mlx)
{
	dst->img_ptr = mlx_xpm_file_to_image(mlx, arg, &dst->width, &dst->height);
	dst->data_ptr = mlx_get_data_addr(dst->img_ptr, &dst->bpp, &dst->size_line,
			&dst->endian);
	return (dst->img_ptr != NULL);
}
