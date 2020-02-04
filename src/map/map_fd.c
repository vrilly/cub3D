/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_fd.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 10:29:18 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/04 10:34:22 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	fd_readline_sb(t_fdstream *file, char **line)
{
	char	*newline;
	int		ret;

	ret = fd_readline(file, &newline);
	if (ret != 1)
		return (ret);
	if (!*newline)
	{
		free(newline);
		ret = fd_readline(file, &newline);
	}
	*line = newline;
	return (ret);
}