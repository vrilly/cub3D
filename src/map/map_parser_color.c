/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parser_color.c                                 :+:    :+:            */
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
			return (clean_mem(&arr));
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

static unsigned int	parse_rgbval(const int *rgbval)
{
	int				i;
	unsigned int	dst;

	i = 0;
	dst = 0;
	while (i < 3)
	{
		dst <<= 8u;
		dst += rgbval[i];
		i++;
	}
	return (dst);
}

/*
** There are a few evaluators( Looking at you >:( ) who like to put
** invalid colour values into map configuration.
** This piece of code filters the invalid input out which the atoi does not
** catch
*/

static int			check_for_dirty_tricks(const char *arg)
{
	if (*arg == ',' || arg[strlen(arg) - 1] == ',')
		return (1);
	if (strstr(arg, ",,"))
		return (1);
	return (0);
}

int					get_color_val(char *arg,
		unsigned int *dst)
{
	int	rgbval[3];

	if (check_for_dirty_tricks(arg))
		return (0);
	if (!atoi_rgbval(rgbval, arg))
		return (0);
	*dst = parse_rgbval(rgbval);
	return (1);
}
