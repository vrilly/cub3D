/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_bmp.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 03:56:22 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/17 04:07:07 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"

void	write_bitmap_to_file(char *path, t_bitmap *bmp)
{
	int fd;

	fd = open(path, O_WRONLY | O_CREAT);
	write(fd, &bmp->header, 14);
	write(fd, &bmp->info, 40);
	write(fd, bmp->bitmap, (bmp->info.width * bmp->info.height * 4));
	close(fd);
}
