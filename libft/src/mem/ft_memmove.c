/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memmove.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 21:53:31 by tjans         #+#    #+#                 */
/*   Updated: 2019/11/11 15:42:28 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*cdst;
	const char	*csrc;

	cdst = dst;
	csrc = src;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		while (len)
		{
			*cdst = *csrc;
			cdst++;
			csrc++;
			len--;
		}
	}
	else
		while (len)
		{
			cdst[len - 1] = csrc[len - 1];
			len--;
		}
	return (dst);
}
