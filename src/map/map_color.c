/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 18:31:43 by tjans         #+#    #+#                 */
/*   Updated: 2020/03/02 19:23:34 by tjans         ########   odam.nl         */
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
	int		ii;

	i = 0;
	arr = ft_split(line, ',');
	if (!arr)
		return (0);
	while (i < 3)
	{
		ii = 0;
		if (!arr[i])
			return (0);
		while (arr[i][ii] == ' ')
			ii++;
		rgbval[i] = ft_atoi(arr[i]);
		if (rgbval[i] > 255 || rgbval[i] < 0 || !ft_isdigit(arr[i][ii]))
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

int					get_color_val(char *arg,
		unsigned int *dst)
{
	int	rgbval[3];

	if (!atoi_rgbval(rgbval, arg))
		return (0);
	*dst = parse_rgbval(rgbval);
	return (1);
}
