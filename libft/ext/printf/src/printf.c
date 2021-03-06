/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 18:29:47 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/07 23:29:16 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "printf.h"

int		ft_fprintf(int fd, const char *fmt, ...)
{
	va_list	args;
	int		ret;

	va_start(args, fmt);
	ret = print_str(fd, fmt, args);
	va_end(args);
	return (ret);
}

int		ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		ret;

	va_start(args, fmt);
	ret = print_str(1, fmt, args);
	va_end(args);
	return (ret);
}

int		ft_snprintf(char *s, size_t n, const char *fmt, ...)
{
	va_list	args;
	int		ret;

	va_start(args, fmt);
	ret = write_str(s, (int)n, fmt, args);
	va_end(args);
	return (ret);
}
