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

/*
** It does exactly what it says.
** Reason? To pass it as a function which fits in the interface
** for handlers
*/

static int			return_true(void)
{
	return (1);
}

static t_mplookup	g_mplookup[MPLOOKUP_SIZE] =
{
	{"R", &map_reader_seq_resolution, 0},
	{"NO", &map_reader_seq_tno, 0},
	{"SO", &map_reader_seq_tso, 0},
	{"WE", &map_reader_seq_twe, 0},
	{"EA", &map_reader_seq_tea, 0},
	{"S", &map_reader_seq_ts, 0},
	{"F", &map_reader_seq_floor_colour, 0},
	{"C", &map_reader_seq_ceiling_colour, 0},
	{".!", (int (*)(char*, t_game*))&map_comment, -1},
	{"..", (int (*)(char*, t_game*))&return_true, -1}
};

t_mplookup			*find_func(char *prefix)
{
	int	i;

	i = 0;
	while (i < MPLOOKUP_SIZE)
	{
		if (ft_strncmp(prefix, g_mplookup[i].prefix,
				ft_strlen(g_mplookup[i].prefix)) == 0)
		{
			if (g_mplookup[i].used == 0)
				g_mplookup[i].used = 1;
			else if (g_mplookup[i].used == 1)
			{
				ftlog(LOG_ERROR, "Double map elements. Aborting!");
				exit(MAP_READ_FAIL);
			}
			return (&g_mplookup[i]);
		}
		i++;
	}
	return (NULL);
}
