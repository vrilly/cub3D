/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ftlog.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 19:15:04 by tjans         #+#    #+#                 */
/*   Updated: 2020/01/06 19:26:09 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** A shitty basic logging thingie which doesn't even take va_args
** But i like using shitty stuff :)
*/

#ifndef FTLOG_H
# define FTLOG_H

enum	e_loglevel {LOG_INFO = 0, LOG_WARN = 1, LOG_ERROR = 2};

void	ftlog_init(int logger_enabled);
void	ftlog(enum e_loglevel log_level, char *logmessage);

#endif
