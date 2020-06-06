/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 16:37:53 by tjans         #+#    #+#                 */
/*   Updated: 2020/03/02 19:36:55 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void					safe_exit(t_game *state, int ret, char *error)
{
	char	errstr[256];

	if (state->error)
	{
		ft_snprintf(errstr, 256, "state->error: %s", state->error);
		ftlog(LOG_ERROR, errstr);
	}
	if (state->window)
		destroy_renderer_window(state);
	if (error)
		ftlog(LOG_ERROR, error);
	if (error && errno)
		ftlog(LOG_ERROR, strerror(errno));
	exit(ret);
}

/*
** Yep, this function does not accept .CuB
** Whoever would do that kind of horrible stuff?
*/

static int				check_filename_valid(char *filename)
{
	size_t	filename_len;

	filename_len = ft_strlen(filename);
	if (filename_len < 4)
		return (0);
	filename += filename_len - 4;
	if (ft_strncmp(filename, ".cub", 5) == 0 ||
	ft_strncmp(filename, ".CUB", 5) == 0)
		return (1);
	return (0);
}

static enum e_cub_error	game_init(t_game *state)
{
	state->mlx_ptr = mlx_init();
	if (!state->mlx_ptr)
		return (MLX_INIT_FAIL);
	if (init_plugins(state))
		return (PLUGIN_FAIL);
	if (!read_map_from_file(state->map_path, state))
		return (MAP_READ_FAIL);
	init_background(state);
	create_renderer_window(state);
	execute_pregame_hook(state);
	mlx_loop_hook(state->mlx_ptr, &render_frame, state);
	if (state->window)
		init_window_hooks(state->window, state);
	mlx_loop(state->mlx_ptr);
	return (NO_ERROR);
}

/*
** There's a --nosync option here
** The movement speed and camera speed are based on the framerate.
** The macOS libmlx does vsync and does not exceed 60fps.
** The linux one i use doesn't and runs at 200fps, so i have to reduce the
** speed to make it playable when the fps is high.
*/

static enum e_cub_error	parse_args(int argc, char **argv, t_game *state)
{
	if (argc < 2)
		return (ARGS_INCOMPLETE);
	state->map_path = argv[1];
	if (argc > 2)
	{
		if (ft_strncmp(argv[2], "--save", 7) == 0)
			state->screenshot = OFFSCREEN_SCREENSHOT;
		else if (ft_strncmp(argv[2], "--nosync", 9) == 0)
		{
			state->config.mov_speed /= 4;
			state->config.cam_speed /= 4;
		}
		else
			return (ARGS_INVALID);
	}
	if (!check_filename_valid(state->map_path))
		return (INVALID_FILENAME);
	return (NO_ERROR);
}

int						main(int argc, char **argv)
{
	t_game				state;
	enum e_cub_error	ret;

	ft_bzero(&state, sizeof(t_game));
	ftlog_init(1);
	load_default_config(&state.config);
	if (argc > 1 && ft_strncmp(argv[1], "--conf", 7) == 0)
		return (start_config_wizard(&state));
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
		safe_exit(&state, 0, NULL);
	else
	{
		ftlog(LOG_ERROR, g_errmsg[ret]);
		safe_exit(&state, ret, state.error);
	}
}
