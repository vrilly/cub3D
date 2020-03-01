/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame_to_bitmap.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 03:50:30 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/20 16:40:02 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"

int		frame_to_bitmap(t_frame *frame, t_bitmap *bmp)
{
	void	*pixelarray;
	int		y;
	int		i;

	y = bmp->info.height - 1;
	i = 0;
	pixelarray = ft_calloc(sizeof(int), bmp->info.width * bmp->info.height);
	if (!pixelarray)
		return (0);
	while (y >= 0)
	{
		ft_memcpy(
				pixelarray + (i * bmp->info.width * 4),
				frame->image_data + (y * frame->size_line),
				bmp->info.width * 4);
		y--;
		i++;
	}
	bmp->bitmap = pixelarray;
	bmp->header.size = 14 + 40 + (bmp->info.width * bmp->info.height * 4);
	return (1);
}
