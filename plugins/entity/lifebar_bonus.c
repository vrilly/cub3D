/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lifebar_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 12:00:00 by tjans         #+#    #+#                 */
/*   Updated: 2020/05/05 12:00:00 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "entity_bonus.h"
#include "../fontrenderer/font_bonus.h"

static void	*get_fb_ptr(t_game *state, int x, int y)
{
	void	*fb;

	fb = state->frame.image_data;
	fb += state->frame.size_line * y;
	fb += x * 4;
	return (fb);
}

static void	draw_border_line(t_game *state, int x, int y)
{
	unsigned int	*fb;
	int				i;

	fb = get_fb_ptr(state, x, y);
	i = 0;
	while (i < LIFEBAR_WIDTH)
	{
		*fb = LB_COLOR_BORDER;
		fb++;
		i++;
	}
}

static void	draw_fill_line(t_game *state, int x, int y, int hp)
{
	unsigned int	*fb;
	int				i;

	fb = get_fb_ptr(state, x, y);
	i = 0;
	while (i < LIFEBAR_WIDTH)
	{
		if (i == 0 || i == LIFEBAR_WIDTH - 1)
			*fb = LB_COLOR_BORDER;
		else
			*fb = (i < hp) ? LB_COLOR_FULL : LB_COLOR_EMPTY;
		fb++;
		i++;
	}
}

void		draw_player_lifebar(t_game *state, int player_hp)
{
	int		x;
	int		y;
	char	hp_str[8];

	if (state->current_map->x_res <= LIFEBAR_WIDTH + 4 ||
	state->current_map->y_res <= LIFEBAR_HEIGHT + 16 ||
	player_hp == -1)
		return ;
	y = state->current_map->y_res - LIFEBAR_HEIGHT - 16;
	x = state->current_map->x_res - LIFEBAR_WIDTH - 4;
	while (y <= state->current_map->y_res - 16)
	{
		if (y == state->current_map->y_res - LIFEBAR_HEIGHT - 16 ||
			y == state->current_map->y_res - 16)
			draw_border_line(state, x, y);
		else
			draw_fill_line(state, x, y, player_hp);
		y++;
	}
	ft_snprintf(hp_str, 8, "HP %d", player_hp);
	draw_string(state, hp_str, x + 8, y - LIFEBAR_HEIGHT + 4);
}
