/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bzero.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:26:43 by tjans         #+#    #+#                 */
/*   Updated: 2019/11/22 19:40:20 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
