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

t_texture		*g_font_ptr;

int				setup(t_texture **ps_ptr)
{
	t_texture	*font;

	font = ft_calloc(1, sizeof(t_texture));
	*ps_ptr = font;
	g_font_ptr = font;
	return (font != NULL);
}

int				pregame_hook(t_game *state, t_texture *font)
{
	font->img_ptr = mlx_xpm_file_to_image(state->mlx_ptr,
			"res/font.xpm", &font->width, &font->height);
	if (!font->img_ptr)
		return (0);
	font->data_ptr = mlx_get_data_addr(font->img_ptr,
			&font->bpp, &font->size_line,
			&font->endian);
	return (font->data_ptr != NULL);
}

static void		*get_data_ptr(int c, int i)
{
	void	*ptr;

	ptr = g_font_ptr->data_ptr;
	if (!ft_isdigit(c))
	{
		if (!ft_isalpha(c))
			return (NULL);
		c = ft_toupper(c) - 'A';
		ptr += g_font_ptr->size_line * CHAR_HEIGHT * 2;
	}
	else
		c -= '0';
	while (c > 7)
	{
		c -= 8;
		ptr += g_font_ptr->size_line * CHAR_HEIGHT;
	}
	ptr += 4 * CHAR_WIDTH * c;
	ptr += g_font_ptr->size_line * i;
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
		fb = (unsigned int *)(state->frame.image_data + state->frame.size_line *
				(y + i));
		fb += x;
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
