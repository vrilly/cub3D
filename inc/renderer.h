/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 05:45:36 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/04 05:46:35 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

typedef struct	s_vertline
{
	int		i;
	char	*tex_pixel;
	char	*data_addr;
	double	step;
	double	t_y;
	int		t_x;
}				t_vertline;

#endif
