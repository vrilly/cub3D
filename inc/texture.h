/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 17:18:20 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/11 17:19:17 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

typedef struct	s_texture
{
	void	*data;

	int		width;
	int		height;
}				t_texture;

#endif
