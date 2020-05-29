/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   config.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 14:02:22 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/23 18:11:00 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

/*
** Configuration struct for the game engine
** This can be saved and loaded from a file for custom keybinds
*/

typedef struct	s_config
{
	int		k_w;
	int		k_a;
	int		k_s;
	int		k_d;
	int		k_esc;
	int		k_left;
	int		k_right;
	int		k_prtscr;

	float	mov_speed;
	float	cam_speed;
}				t_config;

/*
** Struct for the array of customizable keys.
** dst is a pointer to the int in the config struct which is adjustable
** keyname is a human readable name for the key being adjusted
*/

typedef struct	s_reconf
{
	int		*dst;
	char	*keyname;
}				t_reconf;

/*
** Loads default configuration from hardcoded variables
** If a custom configuration file exists it'll give priority to that and
** load from there
*/

void			load_default_config(t_config *config);

/*
** Creates a small rendering window with a key listener and instructs user
** over stdout which key is being adjusted.
*/

int				start_config_wizard(t_game *state);

#endif
