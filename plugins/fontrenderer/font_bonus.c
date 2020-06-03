/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   font_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 12:00:00 by tjans         #+#    #+#                 */
/*   Updated: 2020/05/05 12:00:00 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "font_bonus.h"

t_plugininfo	g_plugininfo = {
	.name = "Font renderer"
};

t_pluginstate	*g_pluginstate_ptr;

int				setup(t_pluginstate **ps_ptr)
{
	t_pluginstate	*state;

	state = ft_calloc(1, sizeof(t_pluginstate));
	*ps_ptr = state;
	g_pluginstate_ptr = state;
	if (!state)
		return (0);
	state->font_bitmap = ft_calloc(1, sizeof(t_texture));
	return (state->font_bitmap != NULL);
}

int				pregame_hook(t_game *state, t_pluginstate *ps)
{
	ps->font_bitmap->img_ptr = mlx_xpm_file_to_image(state->mlx_ptr,
			"res/font.xpm", &ps->font_bitmap->width, &ps->font_bitmap->height);
	if (!ps->font_bitmap->img_ptr)
		return (0);
	ps->font_bitmap->data_ptr = mlx_get_data_addr(ps->font_bitmap->img_ptr,
			&ps->font_bitmap->bpp, &ps->font_bitmap->size_line,
			&ps->font_bitmap->endian);
	return (ps->font_bitmap->data_ptr != NULL);
}

static void		*get_data_ptr(int c, int i)
{
	void	*ptr;

	ptr = g_pluginstate_ptr->font_bitmap->data_ptr;
	if (!ft_isdigit(c))
	{
		if (!ft_isalpha(c))
			return (NULL);
		c = ft_toupper(c) - 'A';
		ptr += g_pluginstate_ptr->font_bitmap->size_line * CHAR_HEIGHT * 2;
	}
	else
		c -= '0';
	while (c > 7)
	{
		c -= 7;
		ptr += g_pluginstate_ptr->font_bitmap->size_line * CHAR_HEIGHT;
	}
	ptr += 4 * CHAR_WIDTH * c;
	ptr += g_pluginstate_ptr->font_bitmap->size_line * i;
	return (ptr);
}

static void		put_char(t_game *state, char c, int x, int y)
{
	unsigned int	*char_data;
	unsigned int	*fb;
	int				i;

	if (x + CHAR_WIDTH > state->current_map->x_res ||
		y + CHAR_HEIGHT > state->current_map->y_res)
		return ;
	i = 0;
	while (i < CHAR_HEIGHT)
	{
		fb = (unsigned int *)state->frame.image_data + state->frame.size_line *
				(y + i);
		fb += 4 * x;
		char_data = get_data_ptr(c, i);
		if (!char_data)
			return ;
		tex_memcpy(fb, char_data, 4 * CHAR_WIDTH);
		i++;
	}
}

void			draw_string(t_game *state, char *str, int x, int y)
{
	while (*str)
	{
		put_char(state, *str, x, y);
		x += CHAR_WIDTH;
		str++;
	}
}
