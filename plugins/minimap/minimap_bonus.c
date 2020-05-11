/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 12:00:00 by tjans         #+#    #+#                 */
/*   Updated: 2020/05/05 12:00:00 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minimap_bonus.h"

t_plugininfo	g_plugininfo = {
		.name = "Minimap",
		.refresh_rate = 60,
};

int	setup(t_pluginstate **ps_ptr)
{
	t_pluginstate *state;

	state = ft_calloc(1, sizeof(t_pluginstate));
	*ps_ptr = state;
	state->fb = ft_calloc(1, sizeof(t_texture));
	if (!state->fb)
		return (0);
	return (1);
}

int	pregame_hook(t_game *state, t_pluginstate *ps)
{
	ps->fb->width = 200;
	ps->fb->height = 200;
	ps->fb->img_ptr = mlx_new_image(state->mlx_ptr, 200, 200);
	if (ps->fb->img_ptr == NULL)
		return (0);
	ps->fb->data_ptr = mlx_get_data_addr(ps->fb->img_ptr, &ps->fb->bpp,
			&ps->fb->size_line, &ps->fb->endian);
	if (ps->fb->data_ptr == NULL)
		return (0);
	return (1);
}

int	frame_hook(t_game *state, t_pluginstate *ps)
{
	draw_tex(state, ps->fb, 0, 0);
	return (1);
}