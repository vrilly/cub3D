/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_error.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 06:15:19 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/18 19:01:28 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** The cub3D Error handler
** It could've been used in a better fashion
** But i did not. So sadly it's rarely used
*/

char	g_errmsg[5][64] = {
	"",
	"MLX Failed to initialize",
	"Couldn't read map",
	"usage: ./cub3D [--save] \033[4;mmapfile\033[0m",
	"Invalid arguments.\nusage: ./cub3D [--save] \033[4;mmapfile\033[0m"
};

void	*reterr(t_game *state, char *err)
{
	if (!state->error || !*(state->error))
		state->error = err;
	return (0);
}
