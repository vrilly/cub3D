/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 12:00:00 by tjans         #+#    #+#                 */
/*   Updated: 2020/05/05 12:00:00 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libplugin_bonus.h"

t_plugininfo	g_plugininfo = {
	.name = "Common utils",
};

/*
** Memcpy which does not copy 0x00000000 pixels, these should be transparent
** Later on i could use some blending algorithm for partial transparency
*/

static void	tex_memcpy(void *dst, void *src, size_t n)
{
	while (n)
	{
		if (*(unsigned int*)src)
			*(unsigned int*)dst = *(unsigned int*)src;
		src++;
		dst++;
		n--;
	}
}

int			draw_tex(t_game *state, t_texture *tex, int x, int y)
{
	int	yp;
	int	offset;
	int t_offset;

	yp = 0;
	if (tex->width + x > state->current_map->x_res ||
		tex->height + y > state->current_map->y_res)
		return (0);
	while (yp < tex->height)
	{
		offset = ((yp + y) * state->frame.size_line) +
				(x * state->frame.bpp / 8);
		t_offset = yp * tex->size_line;
		tex_memcpy(state->frame.image_data + offset, tex->data_ptr + t_offset,
				tex->width * state->frame.bpp / 8);
		yp++;
	}
	return (1);
}

int			setup(void **ptr)
{
	(void)ptr;
	return (1);
}
