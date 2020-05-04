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
	if (state->window)
		destroy_renderer_window(state);
	if (error)
		ftlog(LOG_ERROR, error);
	if (error && errno)
		ftlog(LOG_ERROR, strerror(errno));
	exit(ret);
}

static enum e_cub_error	game_init(t_game *state)
{
	state->mlx_ptr = mlx_init();
	if (!state->mlx_ptr)
		return (MLX_INIT_FAIL);
	if (!read_map_from_file(state->map_path, state))
		return (MAP_READ_FAIL);
	init_background(state);
	create_renderer_window(state);
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
	int	arg_pos;

	arg_pos = 1;
	if (argc < 2)
		return (ARGS_INCOMPLETE);
	if (argc == 3)
	{
		if (ft_strncmp(argv[arg_pos], "--", 2) != 0)
			arg_pos++;
		if (ft_strncmp(argv[arg_pos], "--save", 6) == 0)
			state->screenshot = 2;
		else if (ft_strncmp(argv[arg_pos], "--nosync", 15) == 0)
		{
			state->config.mov_speed /= 3;
			state->config.cam_speed /= 3;
		}
		else
			return (ARGS_INVALID);
	}
	state->map_path = argv[(arg_pos == 1) ? argc - 1 : argc - 2];
	return (NO_ERROR);
}

int						main(int argc, char **argv)
{
	t_game				state;
	enum e_cub_error	ret;

	ft_bzero(&state, sizeof(t_game));
	ftlog_init(1);
	default_config(&state.config);
	if (ft_strncmp(argv[1], "--conf", 6) == 0)
		return (start_reconf(&state));
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
