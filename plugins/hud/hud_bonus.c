/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hud_bonus.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 12:00:00 by tjans         #+#    #+#                 */
/*   Updated: 2020/05/05 12:00:00 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hud_bonus.h"

t_plugininfo	g_plugininfo = {
	.name = "Heads-up display"
};

int				setup(t_pluginstate **ps_ptr)
{
	t_pluginstate *state;

	state = ft_calloc(1, sizeof(t_pluginstate));
	*ps_ptr = state;
	state->fb = ft_calloc(1, sizeof(t_texture));
	if (!state->fb)
		return (0);
	return (1);
}

int				pregame_hook(t_game *state, t_pluginstate *ps)
{
	ps->fb->width = 90;
	ps->fb->height = 90;
	ps->fb->img_ptr = mlx_new_image(state->mlx_ptr, 90, 90);
	if (ps->fb->img_ptr == NULL)
		return (0);
	ps->fb->data_ptr = mlx_get_data_addr(ps->fb->img_ptr, &ps->fb->bpp,
			&ps->fb->size_line, &ps->fb->endian);
	if (ps->fb->data_ptr == NULL)
		return (0);
	if (state->current_map->x_res >= 300 && state->current_map->y_res >= 300)
		ps->enabled = 1;
	return (1);
}

int				update_hook(t_game *state, t_pluginstate *ps)
{
	if (!ps->enabled)
		return (1);
	update(state, ps->fb);
	return (1);
}

int				frame_hook(t_game *state, t_pluginstate *ps)
{
	if (!ps->enabled)
		return (1);
	draw_tex(state, ps->fb, state->current_map->x_res - 90, 0);
	return (1);
}
