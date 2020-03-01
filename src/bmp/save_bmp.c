/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_bmp.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 03:56:22 by tjans         #+#    #+#                 */
/*   Updated: 2020/03/01 19:01:47 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "bitmap.h"

static int	write_bmp_header(int fd, t_bmp_header *hdr)
{
	write(fd, &hdr->bmp_magic, 2);
	write(fd, &hdr->size, 4);
	write(fd, &hdr->reserved, 4);
	write(fd, &hdr->offset, 4);
	return (1);
}

static int	write_dib_header(int fd, t_dib_header *dib)
{
	write(fd, &dib->size, 4);
	write(fd, &dib->width, 4);
	write(fd, &dib->height, 4);
	write(fd, &dib->color_planes, 2);
	write(fd, &dib->bpp, 2);
	write(fd, &dib->compression, 4);
	write(fd, &dib->rawsize, 4);
	write(fd, &dib->hres, 4);
	write(fd, &dib->vres, 4);
	write(fd, &dib->palette_cols, 4);
	write(fd, &dib->important_cols, 4);
	return (1);
}

void		write_bitmap_to_file(char *path, t_bitmap *bmp)
{
	int fd;

	fd = open(path, O_WRONLY | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH);
	write_bmp_header(fd, &bmp->header);
	write_dib_header(fd, &bmp->info);
	write(fd, bmp->bitmap, (bmp->info.width * bmp->info.height * 4));
	close(fd);
	free(bmp->bitmap);
	free(bmp);
}
