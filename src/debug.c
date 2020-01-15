/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 18:31:08 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/15 18:43:48 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"

void	dump_gamestate(t_game *state)
{
	t_vectors vec = state->vec;
	t_rc_params rcp = state->rcp;
	t_draw_p vis = state->vis;
	t_frame	frame = state->frame;
	
	printf("--DBG--\n");
	printf("VECTORS:\npos: %f : %f\ndir: %f : %f\nplane: %f : %f\nmap: %d : %d\n\n",
			vec.pos_x, vec.pos_y, vec.dir_x, vec.dir_y, vec.plane_x, vec.plane_y,
			vec.map_x, vec.map_y);
	printf("CAMERA:\ncam_x: %f\nrc_dir: %f : %f\ns_dist: %f : %f\nd_dist: %f : %f\nwalldist: %f\n\n",
			rcp.camera_x, rcp.rc_dir_x, rcp.rc_dir_y, rcp.s_dist_x, rcp.s_dist_y, rcp.d_dist_x,
			rcp.d_dist_y, rcp.walldist);
	printf("--END--\n\n\n\n");
}
