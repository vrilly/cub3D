/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 17:54:50 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/15 18:03:11 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_H
# define GFX_H

/*
** s_dist = length of ray from cur pos to next side
** d_dist = length of ray from side to next side
*/

typedef struct	s_rc_params
{
	double	camera_x;
	double	rc_dir_x;
	double	rc_dir_y;

	double	s_dist_x;
	double	s_dist_y;
	double	d_dist_x;
	double	d_dist_y;

	double	walldist;

	int		step_x;
	int		step_y;

	int		hit;
	int		side;
}				t_rc_params;

typedef struct	s_draw_p
{
	int		line_height;
	int		line_start;
	int		line_end;
}				t_draw_p;

typedef struct	s_frame
{
	void	*image_ptr;
	char	*image_data;
	int		bpp;
	int		size_line;
	int		endian;
}				t_frame;

#endif
