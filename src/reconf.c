/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reconf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/01 14:02:04 by tjans         #+#    #+#                 */
/*   Updated: 2020/05/01 18:14:18 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_config	g_newcfg;
t_reconf	g_reconf[7] = {
	{&g_newcfg.k_w, "Forwards"},
	{&g_newcfg.k_s, "Backwards"},
	{&g_newcfg.k_a, "Strafe left"},
	{&g_newcfg.k_d, "Strafe right"},
	{&g_newcfg.k_left, "Rotate left"},
	{&g_newcfg.k_right, "Rotate right"},
	{NULL, NULL}
};
int			g_rc_pos = 0;

static void	saveconfig(void)
{
	int	fd;

	fd = open("config.bin", O_WRONLY | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH);
	if (fd <= 0 || write(fd, &g_newcfg, sizeof(t_config)) != sizeof(t_config))
	{
		ft_fprintf(2, "Error creating config file\n");
		exit(-1);
	}
	ft_printf("Configuration saved.\n");
	close(fd);
	exit(0);
}

static int	loophook(void)
{
	return (1);
}

static int	key_hook(int key)
{
	*g_reconf[g_rc_pos].dst = key;
	if (!g_reconf[g_rc_pos + 1].keyname)
		saveconfig();
	g_rc_pos++;
	ft_printf("Please press the key for %s\n", g_reconf[g_rc_pos].keyname);
	return (1);
}

int			start_reconf(t_game *state)
{
	void	*mlx_window;

	state->mlx_ptr = mlx_init();
	mlx_window = mlx_new_window(state->mlx_ptr, 320, 320, "Reconfigure");
	if (!mlx_window)
		safe_exit(state, -1, "Window creation failed.");
	mlx_key_hook(mlx_window, &key_hook, 0);
	mlx_loop_hook(state->mlx_ptr, &loophook, 0);
	ft_printf("Please press the key for %s\n", g_reconf[0].keyname);
	mlx_loop(state->mlx_ptr);
	return (0);
}
