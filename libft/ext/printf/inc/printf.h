/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 11:23:53 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/09 14:12:01 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_flags
{
	char	pad_neg_f_width;
	char	pad_zeroes;
	char	min_field_width;
	char	precision;
	char	print_null_term;

	int		min_field_width_n;
	int		precision_n;
}				t_flags;

typedef struct	s_ctable
{
	char	c_arg;
	char	*(*conv)(va_list args, t_flags *flags);
}				t_ctable;

typedef struct	s_stringbuilder
{
	char					*str;
	int						strlen;
	struct s_stringbuilder	*next;
}				t_stringbuilder;

extern t_ctable	g_ctable[];
t_ctable		*find_conv(char c);

char			*ltoa_base_unsigned(unsigned long n, int base);
char			*ltoa_signed(long n);

t_stringbuilder	*sb_create(char *str, int len);
int				sb_append(t_stringbuilder *root, char *str, int len);
int				sb_strcpy(char *str, t_stringbuilder *root, int max_len);
void			sb_cleanup(t_stringbuilder **root);

t_flags			*parse_flags(const char **fmt, va_list args);
int				print_str(int fd, const char *fmt, va_list args);
int				write_str(char *dst, int dstlen, const char *fmt, va_list args);
int				ft_printf(const char *fmt, ...);
int				ft_fprintf(int fd, const char *fmt, ...);
int				ft_snprintf(char *sm, size_t n, const char *fmt, ...);

#endif
