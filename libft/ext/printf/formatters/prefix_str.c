/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prefix_str.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 15:58:54 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/07 23:31:51 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "formatters.h"

char	*prefix_hex(char *str)
{
	char	*newstr;

	newstr = ft_strjoin("0x", str);
	free(str);
	return (newstr);
}
