/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spr_sort.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 20:55:43 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/30 17:21:14 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sprites(t_sprite_engine *eng)
{
	int			i;
	int			ii;
	int			low;

	i = 0;
	while (i < eng->num_sprites)
	{
		ii = 0;
		low = 0;
		while (ii < eng->num_sprites)
		{
			if (eng->sprites[low]->distance < 0 ||
				eng->sprites[ii]->distance < eng->sprites[low]->distance)
				low = ii;
			ii++;
		}
		eng->sprite_order[i] = low;
		eng->sprites[low]->distance = -1;
		i++;
	}
}
