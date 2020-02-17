/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame_to_bitmap.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 03:50:30 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/17 03:57:48 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"

int		frame_to_bitmap(t_frame *frame, t_bitmap *bmp)
{
	void	*pixelarray;

	pixelarray = ft_calloc(sizeof(int), bmp->info.width * bmp->info.height);
	ft_memcpy(pixelarray, frame->image_data, bmp->info.width * bmp->info.height * 4);
	bmp->bitmap = pixelarray;
	bmp->header.size = 14 + 40 + (bmp->info.width * bmp->info.height * 4);
	return (1);
}
