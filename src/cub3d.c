/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 16:37:53 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/11 17:07:32 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(void)
{
	t_game	state;

	state.mlx_ptr = mlx_init();
	if (!state.mlx_ptr)
		return (0);
	state.current_map = read_map_from_file("map.cub", &state);
	if (!state.current_map)
		return -1;
	ft_putendl_fd("cub3D", 1);
	ft_putnbr_fd(state.current_map->x_res, 1);
	ft_putendl_fd(NULL, 1);
	ft_putnbr_fd(state.current_map->y_res, 1);
	ft_putendl_fd(NULL, 1);
	free(state.current_map);
	while (1) {}
	return 0;
}
