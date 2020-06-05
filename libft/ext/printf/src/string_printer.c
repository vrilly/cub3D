/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_printer.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 12:00:00 by tjans         #+#    #+#                 */
/*   Updated: 2020/05/05 12:00:00 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "printf.h"
#include "utils.h"
#include "formatters.h"

static void	free_if_not_null(void *ptr)
{
	if (ptr)
		free(ptr);
}

static void	sb_create_or_append(t_stringbuilder **root, char *str,
		int str_len)
{
	if (*root)
		sb_append(*root, str, str_len);
	else
		*root = sb_create(str, str_len);
}

static void	handle_noconv(t_stringbuilder **root, const char **str)
{
	char	*ex;
	int		s_len;

	s_len = ft_strclen(*str, '%');
	ex = malloc(sizeof(char) * s_len + 1);
	if (!ex)
		return ;
	ft_strlcpy(ex, *str, s_len + 1);
	*str += s_len;
	sb_create_or_append(root, ex, s_len);
}

static void	eval_conv(t_stringbuilder **root, const char **fmt, va_list args)
{
	t_flags		*flags;
	t_ctable	*converter;
	char		*ret;
	int			ret_len;

	if (**fmt != '%')
		return (void)(handle_noconv(root, fmt));
	flags = parse_flags(fmt, args);
	converter = find_conv(**fmt);
	while (!converter && **fmt != '\0')
	{
		converter = find_conv(**fmt);
		(*fmt)++;
	}
	if (!converter || !flags)
		return (free_if_not_null(flags));
	else
		ret = converter->conv(args, flags);
	if (ret == NULL)
		return (free(flags));
	ret_len = apply_field_width(&ret, flags);
	if (**fmt)
		(*fmt)++;
	sb_create_or_append(root, ret, ret_len);
	return (free(flags));
}

int			write_str(char *dst, int dstlen, const char *fmt, va_list args)
{
	t_stringbuilder	*root;
	int				ret;

	while (*fmt)
		eval_conv(&root, &fmt, args);
	ret = sb_strcpy(dst, root, dstlen);
	sb_cleanup(&root);
	return (ret);
}
