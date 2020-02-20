/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bmp_hdr.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 03:33:17 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/17 04:02:54 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"

t_bitmap	*new_bitmap(int w, int h)
{
	t_bitmap	*bmp;

	bmp = ft_calloc(sizeof(t_bitmap), 1);
	bmp->header.bmp_magic = BM_MAGIC;
	bmp->header.offset = 14 + 40;
	bmp->info.size = 40;
	bmp->info.width = w;
	bmp->info.height = h;
	bmp->info.color_planes = 1;
	bmp->info.bpp = 32;
	return (bmp);
}
