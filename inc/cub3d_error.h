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

enum		e_cub_error {
	NO_ERROR,
	MLX_INIT_FAIL,
	MAP_READ_FAIL,
	ARGS_INCOMPLETE,
	ARGS_INVALID,
	PLUGIN_FAIL,
	INVALID_FILENAME
};

/*
** All the strings for the possible error codes the game can return
*/

extern char	g_errmsg[7][64];

/*
** This function sets the error string in the game state and returns a null ptr
** If the error is already set then it will not overwrite.
** This is meant for the error handling in the game engine, where it can go back
** multiple levels before exiting the program after a (non)-fatal error
*/

void		*set_error(t_game *state, char *err);

#endif
