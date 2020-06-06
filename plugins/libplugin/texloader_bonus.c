/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texloader_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 12:00:00 by tjans         #+#    #+#                 */
/*   Updated: 2020/05/05 12:00:00 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libplugin_bonus.h"

static void	*set_error_lplugin(t_game *state, char *err)
{
	if (!state->error || !*(state->error))
		state->error = err;
	return (0);
}

static int	verify_file(char *arg, t_game *state)
{
	int		fd;
	int		ret;
	char	magic[9];

	fd = open(arg, O_RDONLY);
	ret = 1;
	if (fd <= 0)
	{
		state->error = "File does not exist.";
		return (0);
	}
	if (read(fd, magic, 9) != 9)
		ret = 0;
	if (ft_strncmp(magic, "/* XPM */", 9) != 0)
		ret = 0;
	if (!ret)
		state->error = "Texture is not a valid XPM file";
	close(fd);
	return (ret);
}

int			load_texture_lplugin(t_game *state, char *arg, t_texture *dst,
		void *mlx)
{
	if (!verify_file(arg, state))
		return (0);
	dst->img_ptr = mlx_xpm_file_to_image(mlx, arg, &dst->width, &dst->height);
	dst->data_ptr = mlx_get_data_addr(dst->img_ptr, &dst->bpp, &dst->size_line,
			&dst->endian);
	if (dst->img_ptr == NULL || dst->data_ptr == NULL)
		return ((int)set_error_lplugin(state, "texture load failure"));
	if (16384 % dst->height || 16384 % dst->width)
		return ((int)set_error_lplugin(state, "texture is not a power of 2"));
	return (1);
}
