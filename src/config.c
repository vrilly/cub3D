/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   config.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 14:02:04 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/20 14:05:38 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	default_config(t_config *config)
{
	config->k_w = 13;
	config->k_a = 0;
	config->k_s = 1;
	config->k_d = 2;
	config->k_esc = 53;
}
