/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_error.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 06:15:19 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/04 06:16:48 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_error.h"

char	g_errmsg[3][64] = {
	"",
	"MLX Failed to initialize",
	"Couldn't read map"
};
