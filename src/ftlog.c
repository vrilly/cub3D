/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ftlog.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 19:21:31 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/06 19:41:40 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "ftlog.h"

static int	g_logger_enabled = 0;
const char	*g_log_level_str[3] = { "INFO", "WARN", "ERROR" };
const char	*g_fmt_str = "[%s] %s\n";

void	ftlog_init(int logger_enabled)
{
	g_logger_enabled = logger_enabled;
}

void	ftlog(enum e_loglevel log_level, char *logmessage)
{
	int	log_output;

	log_output = (log_level != LOG_ERROR) ? 1 : 2;
	if (!g_logger_enabled && log_level != LOG_ERROR)
		return ;
	ft_fprintf(log_output, g_fmt_str, g_log_level_str[log_level], logmessage);
}
