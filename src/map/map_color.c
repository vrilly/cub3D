/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 18:31:43 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/04 10:35:15 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int			clean_mem(char ***arr)
{
	size_t	index;

	index = 0;
	while ((*arr)[index])
	{
		free((*arr)[index]);
		index++;
	}
	free(*arr);
	return (0);
}

static int			atoi_rgbval(int *rgbval, char *line)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_split(line, ',');
	if (!arr)
		return (0);
	while (i < 3)
	{
		if (!arr[i])
			return (0);
		rgbval[i] = ft_atoi(arr[i]);
		if (rgbval[i] > 255 || rgbval[i] < 0)
			return (clean_mem(&arr));
		i++;
	}
	clean_mem(&arr);
	return (1);
}

static unsigned int	parse_rgbval(int *rgbval)
{
	int				i;
	unsigned int	dst;

	i = 0;
	dst = 0;
	while (i < 3)
	{
		dst <<= 8;
		dst += rgbval[i];
		i++;
	}
	return (dst);
}

int					get_color_val(const char ti,
		t_fdstream *fs, unsigned int *dst)
{
	char	*line;
	char	*line_i;
	int		rgbval[3];

	if (fd_readline_sb(fs, &line) != 1)
		return (0);
	line_i = line;
	if (*line_i != ti)
		return (0);
	line_i++;
	if (!atoi_rgbval(rgbval, line_i))
		return (0);
	*dst = parse_rgbval(rgbval);
	free(line);
	return (1);
}
