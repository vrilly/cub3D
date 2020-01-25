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

typedef struct	s_config
{
	int	k_w;
	int	k_a;
	int	k_s;
	int	k_d;
	int	k_esc;
	int	k_left;
	int	k_right;
}				t_config;

void			default_config(t_config *config);

#endif
