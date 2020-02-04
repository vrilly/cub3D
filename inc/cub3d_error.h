/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_error.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 06:01:28 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/04 06:14:59 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ERROR_H
# define CUB3D_ERROR_H

enum	e_cub_error {
	NO_ERROR,
	MLX_INIT_FAIL,
	MAP_READ_FAIL
};

char	g_errmsg[3][64];
#endif
