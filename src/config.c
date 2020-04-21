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

#include <X11/keysymdef.h>
#include "config.h"

void	default_config(t_config *config)
{
	config->k_w = XK_w;
	config->k_a = XK_a;
	config->k_s = XK_s;
	config->k_d = XK_d;
	config->k_esc = XK_Escape;
	config->k_left = XK_Left;
	config->k_right = XK_Right;
	config->k_prtscr = XK_Print;
}
