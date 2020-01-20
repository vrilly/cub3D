/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 17:18:20 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/20 17:56:56 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

typedef struct	s_texture
{
	void	*img_ptr;
	void	*data_ptr;

	int		width;
	int		height;

	int		bpp;
	int		size_line;
	int		endian;
}				t_texture;

#endif
