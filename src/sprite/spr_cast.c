/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spr_cast.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 02:04:49 by tjans         #+#    #+#                 */
/*   Updated: 2020/03/02 19:28:18 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "spr_cast.h"

static int	bnd(int calc, int max)
{
	if (calc < 0)
		return (0);
	if (max != 0 && calc >= max)
		return (max - 1);
	return (calc);
}

static void	cast_sprite(t_calc c, t_frame *frame, t_texture *tex, double *zbuf)
{
	t_cast	cc;

	cc.x = c.draw_s_x;
	while (cc.x < c.draw_e_x)
	{
		cc.tx = (256 * (cc.x - (-c.width / 2 + c.screen_x)) *
				tex->width / c.width) / 256;
		cc.y = c.draw_s_y;
		if (c.tr_y > 0 && cc.x > 0 && cc.x < c.res_x && c.tr_y < zbuf[cc.x])
			while (cc.y < c.draw_e_y)
			{
				cc.d = cc.y * 256 - c.res_y * 128 + c.height * 128;
				cc.ty = ((cc.d * tex->height) / c.height) / 256;
				cc.tex_pixel = tex->data_ptr + cc.tx * 4 + ((cc.ty
							& (tex->height - 1)) * tex->size_line);
				cc.data_addr = frame->image_data +
					(cc.y * frame->size_line) +
					(cc.x * (frame->bpp / 8));
				if (*(unsigned int*)cc.tex_pixel != 0xFF000000 &&
					*(unsigned int*)cc.tex_pixel)
					*(unsigned int*)cc.data_addr = *(unsigned int*)cc.tex_pixel;
				cc.y++;
			}
		cc.x++;
	}
}

static void	draw_sprite(t_sprite *sprite, t_game *state, t_vectors *vec)
{
	t_calc	c;

	c.res_x = state->current_map->x_res;
	c.res_y = state->current_map->y_res;
	c.pos_x = sprite->x_pos - vec->pos_x;
	c.pos_y = sprite->y_pos - vec->pos_y;
	c.invert = 1.0 / (vec->plane_x * vec->dir_y - vec->dir_x * vec->plane_y);
	c.tr_x = c.invert * (vec->dir_y * c.pos_x - vec->dir_x * c.pos_y);
	c.tr_y = c.invert * (-vec->plane_y * c.pos_x + vec->plane_x * c.pos_y);
	c.screen_x = (int)((c.res_x / 2) * (1 + c.tr_x / c.tr_y));
	c.height = abs((int)(c.res_y / c.tr_y)) / 1.33;
	c.draw_s_y = bnd(-c.height / 2 + c.res_y / 2, 0);
	c.draw_e_y = bnd(c.height / 2 + c.res_y / 2, c.res_y);
	c.width = abs((int)(c.res_x / c.tr_y)) / 1.33;
	c.draw_s_x = bnd(-c.width / 2 + c.screen_x, 0);
	c.draw_e_x = bnd(c.width / 2 + c.screen_x, c.res_x);
	cast_sprite(c, &state->frame, sprite->texture, state->spr.zbuffer);
}

void		cast_sprites(t_game *state)
{
	int			i;
	t_sprite	*spr;

	i = 0;
	while (i < state->spr.num_sprites)
	{
		spr = state->spr.sprites[state->spr.sprite_order
			[state->spr.num_sprites - i - 1]];
		draw_sprite(spr, state, &state->vec);
		i++;
	}
}
