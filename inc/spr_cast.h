/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spr_cast.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 02:15:06 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/04 05:44:26 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPR_CAST_H
# define SPR_CAST_H

/*
** pos:		relative position to camera
** invert:	inverse matrix for matrix multiplication
** tr:		depth transformation
** draw:	line drawing parameters (start and end)
*/

typedef struct	s_calc
{
	double	pos_x;
	double	pos_y;

	double	invert;

	double	tr_x;
	double	tr_y;

	int		screen_x;
	int		height;
	int		draw_s_y;
	int		draw_e_y;

	int		width;
	int		draw_s_x;
	int		draw_e_x;

	int		res_x;
	int		res_y;
}				t_calc;

typedef struct	s_cast
{
	int		x;
	int		y;

	int		tx;
	int		ty;

	int		d;

	char	*tex_pixel;
	char	*data_addr;
}				t_cast;

#endif
