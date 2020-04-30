/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_bmp.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 03:56:22 by tjans         #+#    #+#                 */
/*   Updated: 2020/03/01 19:55:01 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "bitmap.h"

/*
** These functions write the structs to the file
** With most compilers you can also create PACKED structs and
** write the struct itself as bitmap with one write call
** But here we do it Norme proof
*/

static int	write_bmp_header(int fd, t_bmp_header *hdr)
{
	ssize_t	written;

	written = write(fd, &hdr->bmp_magic, 2);
	written += write(fd, &hdr->size, 4);
	written += write(fd, &hdr->reserved, 4);
	written += write(fd, &hdr->offset, 4);
	return (written == 14);
}

static int	write_dib_header(int fd, t_dib_header *dib)
{
	ssize_t	written;

	written = write(fd, &dib->size, 4);
	written += write(fd, &dib->width, 4);
	written += write(fd, &dib->height, 4);
	written += write(fd, &dib->color_planes, 2);
	written += write(fd, &dib->bpp, 2);
	written += write(fd, &dib->compression, 4);
	written += write(fd, &dib->rawsize, 4);
	written += write(fd, &dib->hres, 4);
	written += write(fd, &dib->vres, 4);
	written += write(fd, &dib->palette_cols, 4);
	written += write(fd, &dib->important_cols, 4);
	return (written == 40);
}

int			write_bitmap_to_file(char *path, t_bitmap *bmp)
{
	int fd;
	int	ret;

	ret = 1;
	fd = open(path, O_WRONLY | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH);
	if (!fd || !write_bmp_header(fd, &bmp->header) ||
	!write_dib_header(fd, &bmp->info))
		ret = 0;
	if (write(fd, bmp->bitmap, (bmp->info.width * bmp->info.height * 4)) !=
	(bmp->info.width * bmp->info.height * 4))
		ret = 0;
	close(fd);
	free(bmp->bitmap);
	free(bmp);
	return (ret);
}
