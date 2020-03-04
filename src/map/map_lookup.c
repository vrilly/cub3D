/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_lookup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 18:57:08 by tjans         #+#    #+#                 */
/*   Updated: 2020/03/04 18:50:34 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

#define MPLOOKUP_SIZE 10

static int			return_true(void)
{
	return (1);
}

static t_mplookup	g_mplookup[MPLOOKUP_SIZE] =
{
	{"R", &map_reader_seq_resolution},
	{"NO", &map_reader_seq_tno},
	{"SO", &map_reader_seq_tso},
	{"WE", &map_reader_seq_twe},
	{"EA", &map_reader_seq_tea},
	{"S", &map_reader_seq_ts},
	{"F", &map_reader_seq_floor_colour},
	{"C", &map_reader_seq_ceiling_colour},
	{".!", (int (*)(char*, t_game*))&map_comment},
	{"..", (int (*)(char*, t_game*))&return_true}
};

t_mplookup			*find_func(char *prefix)
{
	int	i;

	i = 0;
	while (i < MPLOOKUP_SIZE)
	{
		if (ft_strncmp(prefix, g_mplookup[i].prefix,
				ft_strlen(g_mplookup[i].prefix)) == 0)
			return (&g_mplookup[i]);
		i++;
	}
	return (NULL);
}
