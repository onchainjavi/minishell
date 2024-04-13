/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 01:18:14 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/14 15:24:50 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "list.h"
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

# define ERROR	1
# define SUCCESS 0

typedef enum s_redir_type
{
	NO_REDIR,
	IN,
	HERE_DOC,
	OUT,
	OUT_APPEND,
}	t_type;

typedef struct s_in_out
{
	t_type			type;
	char			*file;
	struct s_in_out	*next;
}	t_io;

typedef struct s_cmnd
{
	char			**args;
	t_io			*redir;
	struct s_cmnd	*next;
}	t_cmnd;

typedef struct s_minishell
{
	t_cmnd	*cmnd_list;
	char	**_envp;
	char	**_export;
	char	*home;
	char	*oldpwd;
	int		exit_code;
}	t_minishell;

t_minishell		*init_minishell(int argc, char **argv, char **envp, \
								t_minishell *shell);
int				free_minishell(t_minishell shell);

void			set_minishell_terminal(void);
void			rollback_terminal_setting(void);
void			set_default_minishell_signal(void);
void			set_execution_signal(void);

int				append_new_envvar(t_minishell *shell, char **_export, \
											char **_envp, char *arg);
int				update_shlvl(t_minishell *shell, char **envp);

void			free_cmnd_list(t_cmnd **cmnd_list);

/*-----BUILTINS-----*/
void			env(t_minishell *shell);
int				_export(t_minishell *shell, char **args);
int				cd(t_minishell *shell, char *path);
void			pwd(void);
int				echo(t_minishell *shell, char **args);
int				exit_sh(char **args, int *exit_code);
int				_unset(char **args, char **_envp, char **_export);

char			**realloc_char2p(char **arr, int new_size);

#endif
