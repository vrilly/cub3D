/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   config.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 14:02:04 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/23 18:14:18 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	default_config(t_config *config)
{
	config->k_w = 119;
	config->k_a = 97;
	config->k_s = 115;
	config->k_d = 100;
	config->k_esc = 65307;
	config->k_left = 65361;
	config->k_right = 65363;
}
