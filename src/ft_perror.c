/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:32:11 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/14 16:17:43 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err_msg.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void	ft_perror(int errtype, ...)
{
	va_list	ap;
	char	*errstr;

	va_start(ap, errtype);
	if (errtype == UNEXPECTED_TOKEN)
		errstr = "syntax error near unexpected token \'%s\'\n";
	else if (errtype == COMMAND_NOT_FOUND)
		errstr = "%s: command not found\n";
	else if (errtype == NO_FILE_OR_DIRECTORY)
		errstr = "%s: No such file or directory\n";
	else if (errtype == PERMISSION_DENIED)
		errstr = "%s: Permission denied\n";
	else if (errtype == IS_A_DIRECTORY)
		errstr = "%s: Is a directory\n";
	else if (errtype == IS_A_DIRECTORY_I)
		errstr = "%s: is a directory\n";
	else if (errtype == TOO_MANY_ARGS)
		errstr = "exit: too many arguments\n";
	else
		errstr = "unkown error\n";
	ft_printf_fd(STDERR_FILENO, "minishell: ");
	if (errtype < 10)
		ft_printf_fd(STDERR_FILENO, errstr, va_arg(ap, char *));
	else
		ft_printf_fd(STDERR_FILENO, errstr);
}

void	ft_perror2(int errtype, ...)
{
	va_list	ap;
	char	*errstr;

	va_start(ap, errtype);
	if (errtype == AMBIGUOUS_REDIRECT)
		errstr = "%s: ambiguous redirect\n";
	else if (errtype == EXPORT_INVALID_IDENTIFIER)
		errstr = "export: `%s\': not a valid identifier\n";
	else if (errtype == HIGH_SHELL_LEVEL)
		errstr = "warning: shell level (%s) too high, resetting to 1\n";
	else if (errtype == NUMERIC_ARGUMENT)
		errstr = "exit: %s: numeric argument required\n";
	else
		errstr = "unkown error\n";
	ft_printf_fd(STDERR_FILENO, "minishell: ");
	if (errtype < 10)
		ft_printf_fd(STDERR_FILENO, errstr, va_arg(ap, char *));
	else
		ft_printf_fd(STDERR_FILENO, errstr);
}
