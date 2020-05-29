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

#include "cub3d.h"

static int	load_config(t_config *config)
{
	int	fd;

	fd = open("config.bin", O_RDONLY);
	if (fd <= 0)
		return (0);
	if (read(fd, config, sizeof(t_config)) != sizeof(t_config))
	{
		ftlog(LOG_ERROR, "config.bin corrupted. using default config");
		return (0);
	}
	ftlog(LOG_INFO, "Loaded configuration from config.bin");
	return (1);
}

/*
** Mov and cam speed are always zero in the configuration.
** So we need to load, set mov+cam speed and then return before setting keys
** to default
*/

void		load_default_config(t_config *config)
{
	int	ext_cfg;

	ext_cfg = load_config(config);
	config->k_esc = 53;
	config->k_prtscr = 105;
	config->mov_speed = 0.125;
	config->cam_speed = 0.0418;
	if (ext_cfg)
		return ;
	config->k_w = 13;
	config->k_a = 0;
	config->k_s = 1;
	config->k_d = 2;
	config->k_left = 123;
	config->k_right = 124;
}
