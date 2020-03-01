/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bitmap.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 03:18:54 by tjans         #+#    #+#                 */
/*   Updated: 2020/03/01 18:58:01 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_H
# define BITMAP_H
# define BM_MAGIC 0x4D42

# include "cub3d.h"

typedef struct	s_bmp_header
{
	short	bmp_magic;
	int		size;
	int		reserved;
	int		offset;
}				t_bmp_header;

typedef struct	s_dib_header
{
	int		size;
	int		width;
	int		height;
	short	color_planes;
	short	bpp;
	int		compression;
	int		rawsize;
	int		hres;
	int		vres;
	int		palette_cols;
	int		important_cols;
}				t_dib_header;

typedef struct	s_bitmap
{
	t_bmp_header	header;
	t_dib_header	info;
	void			*bitmap;
}				t_bitmap;

t_bitmap		*new_bitmap(int w, int h);
int				frame_to_bitmap(t_frame *frame, t_bitmap *bmp);
void			write_bitmap_to_file(char *path, t_bitmap *bmp);

#endif
