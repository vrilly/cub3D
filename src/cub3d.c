/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 16:37:53 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/18 18:45:58 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include "cub3d.h"

static enum e_cub_error	game_init(t_game *state)
{
	default_config(&state->config);
	state->mlx_ptr = mlx_init();
	if (!state->mlx_ptr)
		return (MLX_INIT_FAIL);
	if (!read_map_from_file(state->map_path, state))
		return (MAP_READ_FAIL);
	init_background(state);
	create_renderer_window(state);
	while (1)
	{
		mlx_loop_hook(state->mlx_ptr, &render_frame, state);
		mlx_hook(state->window, KeyPress, KeyPressMask, &hook_keydown, state);
		mlx_hook(state->window, KeyRelease, KeyReleaseMask, &hook_keyup,
				state);
		mlx_hook(state->window, DestroyNotify, 0, (int (*)())&exit, 0);
		mlx_loop(state->mlx_ptr);
	}
	return (0);
}

static enum e_cub_error	parse_args(int argc, char **argv, t_game *state)
{
	if (argc < 2)
		return (ARGS_INCOMPLETE);
	state->map_path = argv[argc - 1];
	return (NO_ERROR);
}

int						main(int argc, char **argv)
{
	t_game				state;
	enum e_cub_error	ret;

	ftlog_init(1);
	state.screenshot = 1;
	ret = parse_args(argc, argv, &state);
	if (ret != NO_ERROR)
	{
		ftlog(LOG_ERROR, g_errmsg[ret]);
		if (state.error)
			ftlog(LOG_ERROR, state.error);
		return (ret);
	}
	ret = game_init(&state);
	if (ret == NO_ERROR)
		return (0);
	else
	{
		ftlog(LOG_ERROR, g_errmsg[ret]);
		if (state.error)
			ftlog(LOG_ERROR, state.error);
		return (ret);
	}
}
