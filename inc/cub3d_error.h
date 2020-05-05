/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_error.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 06:01:28 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/18 16:21:10 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ERROR_H
# define CUB3D_ERROR_H

enum	e_cub_error {
	NO_ERROR,
	MLX_INIT_FAIL,
	MAP_READ_FAIL,
	ARGS_INCOMPLETE,
	ARGS_INVALID,
	PLUGIN_FAIL
};

char	g_errmsg[6][64];
#endif
