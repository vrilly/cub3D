/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_sign.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 12:57:32 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/07 23:27:04 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "printf.h"
#include "conversions.h"

char	*p_sign(va_list arg, t_flags *flags)
{
	if (!arg || !flags)
		return (ft_strdup("%"));
	return (ft_strdup("%"));
}
