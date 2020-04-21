/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memcpy.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 15:58:52 by tjans         #+#    #+#                 */
/*   Updated: 2020/02/04 05:01:46 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (!src && !dst)
		return (NULL);
	while (n)
	{
		if (n > sizeof(long))
		{
			*(unsigned long*)dst = *(unsigned long*)src;
			src += sizeof(long);
			dst += sizeof(long);
			n -= sizeof(long);
		}
		else
		{
			*(unsigned char*)dst = *(unsigned char*)src;
			src++;
			dst++;
			n--;
		}
	}
	return (dst);
}
